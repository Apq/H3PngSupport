static void StartPlugin()
{
    WriteLog("PngSupport 已加载。API v%d。", PngSupport_GetApiVersion());
    WriteLog("导出函数：PngSupport_LoadSurface16 / FreeSurface16 / DrawSurface16 / DrawSurface16Full。");
}

// ========== DllMain ==========

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved)
{
    static bool initialized = false;
    if (reason == DLL_PROCESS_ATTACH && !initialized) {
        initialized = true;
        g_hModule = hModule;
        GetModuleFileNameA(hModule, g_ini_path, MAX_PATH);
        char* dot = strrchr(g_ini_path, '.');
        if (dot) strcpy(dot, ".ini");
        g_disable_log = ReadDisableLogFromIniFileA(g_ini_path);
        SetupDatedLogPathAndCleanup(hModule);
        WriteLog("PngSupport 正在加载。");

        _P = GetPatcher();
        if (!_P) {
            WriteLog("GetPatcher 失败；插件仍保留导出 API，但不注册 Patcher 实例。");
            return TRUE;
        }
        _PI = _P->CreateInstance("HD.Plugin.PngSupport");
        if (!_PI) {
            WriteLog("CreateInstance 失败；插件仍保留导出 API。");
            return TRUE;
        }
        StartPlugin();
    }
    return TRUE;
}
