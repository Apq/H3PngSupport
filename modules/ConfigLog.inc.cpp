// ========== 配置与日志 ==========

static char g_ini_path[MAX_PATH];
static char g_log_path[MAX_PATH];
static wchar_t g_log_path_w[MAX_PATH * 2];
static HMODULE g_hModule = nullptr;

static const int MAX_LOG_FILES_TO_KEEP = 30;
static const int MAX_LOG_FILES_TO_SCAN = 1024;

struct LogFileEntryW {
    wchar_t path[MAX_PATH * 2];
    FILETIME last_write;
};

static int __cdecl CompareLogFileEntryW(const void* a, const void* b)
{
    const LogFileEntryW* la = (const LogFileEntryW*)a;
    const LogFileEntryW* lb = (const LogFileEntryW*)b;
    int cmp = CompareFileTime(&la->last_write, &lb->last_write);
    if (cmp != 0) return cmp;
    return _wcsicmp(la->path, lb->path);
}

static void CleanupOldLogFilesW(const wchar_t* log_dir, const wchar_t* log_base, const wchar_t* current_log_path)
{
    if (!log_dir || !log_dir[0] || !log_base || !log_base[0]) return;

    wchar_t pattern[MAX_PATH * 2];
    _snwprintf_s(pattern, _countof(pattern), _TRUNCATE, L"%s\\%s_*.log", log_dir, log_base);

    LogFileEntryW* entries = (LogFileEntryW*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, MAX_LOG_FILES_TO_SCAN * sizeof(LogFileEntryW));
    if (!entries) return;
    int count = 0;
    bool current_found = false;

    WIN32_FIND_DATAW fd;
    HANDLE h = FindFirstFileW(pattern, &fd);
    if (h == INVALID_HANDLE_VALUE) { HeapFree(GetProcessHeap(), 0, entries); return; }
    do {
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;
        if (count >= MAX_LOG_FILES_TO_SCAN) break;
        _snwprintf_s(entries[count].path, _countof(entries[count].path), _TRUNCATE, L"%s\\%s", log_dir, fd.cFileName);
        entries[count].last_write = fd.ftLastWriteTime;
        if (current_log_path && _wcsicmp(entries[count].path, current_log_path) == 0) current_found = true;
        ++count;
    } while (FindNextFileW(h, &fd));
    FindClose(h);

    int keep_existing = current_found ? MAX_LOG_FILES_TO_KEEP : (MAX_LOG_FILES_TO_KEEP - 1);
    if (keep_existing < 0) keep_existing = 0;
    if (count <= keep_existing) { HeapFree(GetProcessHeap(), 0, entries); return; }

    qsort(entries, count, sizeof(entries[0]), CompareLogFileEntryW);
    int delete_count = count - keep_existing;
    for (int i = 0; i < delete_count; ++i) DeleteFileW(entries[i].path);
    HeapFree(GetProcessHeap(), 0, entries);
}

static void SetupDatedLogPathAndCleanup(HMODULE hModule)
{
    wchar_t module_path[MAX_PATH * 2] = { 0 };
    GetModuleFileNameW(hModule, module_path, _countof(module_path));

    wchar_t dir[MAX_PATH * 2] = { 0 };
    wchar_t base[MAX_PATH * 2] = { 0 };
    const wchar_t* slash1 = wcsrchr(module_path, L'\\');
    const wchar_t* slash2 = wcsrchr(module_path, L'/');
    const wchar_t* slash = slash1 > slash2 ? slash1 : slash2;
    const wchar_t* name = slash ? slash + 1 : module_path;
    if (slash) {
        int len = (int)(slash - module_path);
        if (len >= (int)_countof(dir)) len = (int)_countof(dir) - 1;
        memcpy(dir, module_path, len * sizeof(wchar_t));
        dir[len] = 0;
    } else {
        wcscpy_s(dir, L".");
    }
    wcsncpy_s(base, name, _TRUNCATE);
    wchar_t* dot = wcsrchr(base, L'.');
    if (dot) *dot = 0;

    SYSTEMTIME st;
    GetLocalTime(&st);
    _snwprintf_s(g_log_path_w, _countof(g_log_path_w), _TRUNCATE,
        L"%s\\%s_%04u%02u%02u_%02u%02u%02u.log",
        dir, base, st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    WideCharToMultiByte(CP_UTF8, 0, g_log_path_w, -1, g_log_path, sizeof(g_log_path), nullptr, nullptr);
    CleanupOldLogFilesW(dir, base, g_log_path_w);
}

static void WriteLog(const char* fmt, ...)
{
    if (!g_log_path[0]) return;

    FILE* f = nullptr;
    fopen_s(&f, g_log_path, "ab");
    if (!f) return;

    long pos = ftell(f);
    if (pos == 0) {
        const unsigned char bom[3] = {0xEF, 0xBB, 0xBF};
        fwrite(bom, 1, 3, f);
    }

    SYSTEMTIME st;
    GetLocalTime(&st);
    fprintf(f, "[%04u-%02u-%02u %02u:%02u:%02u.%03u] ",
        st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

    va_list ap;
    va_start(ap, fmt);
    vfprintf(f, fmt, ap);
    va_end(ap);
    fprintf(f, "\r\n");
    fclose(f);
}
