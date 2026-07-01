#pragma once

//map object types
#define MAPOBJECT_BOAT 8
#define MAPOBJECT_HERO 34
#define MAPOBJECT_TOWN 98

#define GAMETYPE_HOTSEAT 3

#define MAPTYPE_SOD 2
#define MAPTYPE_AB 1
#define MAPTYPE_ROE 0

#define ID_NONE -1

// creatures ids
#define CID_PIKEMAN   0
#define CID_HALBERDIER  1
#define CID_ARCHER   2
#define CID_MARKSMAN  3
#define CID_GRIFFIN   4
#define CID_ROYAL_GRIFFIN 5
#define CID_SWORDSMAN  6
#define CID_CRUSADER  7
#define CID_MONK   8
#define CID_ZEALOT   9
#define CID_CAVALIER  10
#define CID_CHAMPION  11
#define CID_ANGEL   12
#define CID_ARCHANGEL  13

#define CID_CENTAUR    14
#define CID_CENTAUR_CAPTAIN  15
#define CID_DWARF    16
#define CID_BATTLE_DWARF  17
#define CID_WOOD_ELF   18
#define CID_GRAND_ELF   19
#define CID_PEGASUS    20
#define CID_SILVER_PEGASUS  21
#define CID_DENDROID_GUARD  22
#define CID_DENDROID_SOLDIER 23
#define CID_UNICORN    24
#define CID_WAR_UNICORN   25
#define CID_GREEN_DRAGON  26
#define CID_GOLD_DRAGON   27

#define CID_GREMLIN    28
#define CID_MASTER_GREMLIN  29
#define CID_STONE_GARGOYLE  30
#define CID_OBSIDIAN_GARGOYLE 31
#define CID_STONE_GOLEM   32
#define CID_IRON_GOLEM   33
#define CID_MAGE    34
#define CID_ARCH_MAGE   35
#define CID_GENIE    36
#define CID_MASTER_GENIE  37
#define CID_NAGA    38
#define CID_NAGA_QUEEN   39
#define CID_GIANT    40
#define CID_TITAN    41

#define CID_IMP    42
#define CID_FAMILIAR  43
#define CID_GOG    44
#define CID_MAGOG   45
#define CID_HELL_HOUND  46
#define CID_CERBERUS  47
#define CID_DEMON   48
#define CID_HORNED_DEMON 49
#define CID_PIT_FIEND  50
#define CID_PIT_LORD  51
#define CID_EFREETI   52
#define CID_EFREET_SULTAN 53
#define CID_DEVIL   54
#define CID_ARCH_DEVIL  55

#define CID_SKELETON   56
#define CID_SKELETON_WARRIOR 57
#define CID_WALKING_DEAD  58
#define CID_ZOMBIE    59
#define CID_WIGHT    60
#define CID_WRAITH    61
#define CID_VAMPIRE    62
#define CID_VAMPIRE_LORD  63
#define CID_LICH    64
#define CID_POWER_LICH   65
#define CID_BLACK_KNIGHT  66
#define CID_DREAD_KNIGHT  67
#define CID_BONE_DRAGON   68
#define CID_GHOST_DRAGON  69

#define CID_TROGLODYTE   70
#define CID_INFERNAL TROGLODYTE 71
#define CID_HARPY    72
#define CID_HARPY_HAG   73
#define CID_BEHOLDER   74
#define CID_EVIL_EYE   75
#define CID_MEDUSA    76
#define CID_MEDUSA_QUEEN  77
#define CID_MINOTAUR   78
#define CID_MINOTAUR_KING  79
#define CID_MANTICORE   80
#define CID_SCORPICORE   81
#define CID_RED_DRAGON   82
#define CID_BLACK_DRAGON  83

#define CID_GOBLIN    84
#define CID_HOBGOBLIN   85
#define CID_WOLF_RIDER   86
#define CID_WOLF_RAIDER   87
#define CID_ORC     88
#define CID_ORC_CHIEFTAIN  89
#define CID_OGRE    90
#define CID_OGRE_MAGE   91
#define CID_ROC     92
#define CID_THUNDERBIRD   93
#define CID_CYCLOPS    94
#define CID_CYCLOPS_KING  95
#define CID_BEHEMOTH   96
#define CID_ANCIENT_BEHEMOTH 97

#define CID_GNOLL    98
#define CID_GNOLL_MARAUDER  99
#define CID_LIZARDMAN   100
#define CID_LIZARD_WARRIOR  101
#define CID_GORGON    102
#define CID_MIGHTY_GORGON  103
#define CID_SERPENT_FLY   104
#define CID_DRAGON_FLY   105
#define CID_BASILISK   106
#define CID_GREATER_BASILISK 107
#define CID_WYVERN    108
#define CID_WYVERN_MONARCH  109
#define CID_HYDRA    110
#define CID_CHAOS_HYDRA   111

#define CID_AIR_ELEMENTAL 112
#define CID_EARTH_ELEMENTAL 113
#define CID_FIRE_ELEMENTAL 114
#define CID_WATER_ELEMENTAL 115
#define CID_GOLD_GOLEM  116
#define CID_DIAMOND_GOLEM 117

#define CID_PIXIE    118
#define CID_SPRITE    119
#define CID_PSYCHIC_ELEMENTAL 120
#define CID_MAGIC_ELEMENTAL  121
#define CID_NOT_USED1   122
#define CID_ICE_ELEMENTAL  123
#define CID_NOT_USED2   124
#define CID_MAGMA_ELEMENTAL  125
#define CID_NOT_USED3   126
#define CID_STORM_ELEMENTAL  127
#define CID_NOT_USED4   128
#define CID_ENERGY_ELEMENTAL 129
#define CID_FIREBIRD   130
#define CID_PHOENIX    131

#define CID_AZURE DRAGON 132
#define CID_CRYSTAL DRAGON 133
#define CID_FAERIE DRAGON 134
#define CID_RUST DRAGON  135
#define CID_ENCHANTER  136
#define CID_SHARPSHOOTER 137
#define CID_HALFLING  138
#define CID_PEASANT   139
#define CID_BOAR   140
#define CID_MUMMY   141
#define CID_NOMAD   142
#define CID_ROGUE   143
#define CID_TROLL   144

#define CID_CATAPULT  145
#define CID_BALLISTA  146
#define CID_FIRST_AID_TENT 147
#define CID_AMMO_CART  148
#define CID_ARROW_TOWER  149


/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

// arts ids
 
#define AID_SPELL_BOOK 0 
#define AID_SPELL_SCROLL 1 
#define AID_THE_GRAIL 2 
#define AID_CATAPULT 3 
#define AID_BALLISTA 4 
#define AID_AMMO_CART 5 
#define AID_FIRST_AID_TENT 6 
#define AID_CENTAURS_AXE 7 
#define AID_BLACKSHARD_OF_THE_DEAD_KNIGHT 8 
#define AID_GREATER_GNOLLS_FLAIL 9 
#define AID_OGRES_CLUB_OF_HAVOC 10 
#define AID_SWORD_OF_HELLFIRE 11 
#define AID_TITANS_GLADIUS 12 
#define AID_SHIELD_OF_THE_DWARVEN_LORDS 13 
#define AID_SHIELD_OF_THE_YAWNING_DEAD 14 
#define AID_BUCKLER_OF_THE_GNOLL_KING 15 
#define AID_TARG_OF_THE_RAMPAGING_OGRE 16 
#define AID_SHIELD_OF_THE_DAMNED 17 
#define AID_SENTINELS_SHIELD 18 
#define AID_HELM_OF_THE_ALABASTER_UNICORN 19 
#define AID_SKULL_HELMET 20 
#define AID_HELM_OF_CHAOS 21 
#define AID_CROWN_OF_THE_SUPREME_MAGI 22 
#define AID_HELLSTORM_HELMET 23 
#define AID_THUNDER_HELMET 24 
#define AID_BREASTPLATE_OF_PETRIFIED_WOOD 25 
#define AID_RIB_CAGE 26 
#define AID_SCALES_OF_THE_GREATER_BASILISK 27 
#define AID_TUNIC_OF_THE_CYCLOPS_KING 28 
#define AID_BREASTPLATE_OF_BRIMSTONE 29 
#define AID_TITANS_CUIRASS 30 
#define AID_ARMOR_OF_WONDER 31 
#define AID_SANDALS_OF_THE_SAINT 32 
#define AID_CELESTIAL_NECKLACE_OF_BLISS 33 
#define AID_LIONS_SHIELD_OF_COURAGE 34 
#define AID_SWORD_OF_JUDGEMENT 35 
#define AID_HELM_OF_HEAVENLY_ENLIGHTENMENT 36 
#define AID_QUIET_EYE_OF_THE_DRAGON 37 
#define AID_RED_DRAGON_FLAME_TONGUE 38 
#define AID_DRAGON_SCALE_SHIELD 39 
#define AID_DRAGON_SCALE_ARMOR 40 
#define AID_DRAGONBONE_GREAVES 41 
#define AID_DRAGON_WING_TABARD 42 
#define AID_NECKLACE_OF_DRAGONTEETH 43 
#define AID_CROWN_OF_DRAGONTOOTH 44 
#define AID_STILL_EYE_OF_THE_DRAGON 45 
#define AID_CLOVER_OF_FORTUNE 46 
#define AID_CARDS_OF_PROPHECY 47 
#define AID_LADYBIRD_OF_LUCK 48 
#define AID_BADGE_OF_COURAGE 49 
#define AID_CREST_OF_VALOR 50 
#define AID_GLYPH_OF_GALLANTRY 51 
#define AID_SPECULUM 52 
#define AID_SPYGLASS 53 
#define AID_AMULET_OF_THE_UNDERTAKER 54 
#define AID_VAMPIRES_COWL 55 
#define AID_DEAD_MANS_BOOTS 56 
#define AID_GARNITURE_OF_INTERFERENCE 57 
#define AID_SURCOAT_OF_COUNTERPOISE 58 
#define AID_BOOTS_OF_POLARITY 59 
#define AID_BOW_OF_ELVEN_CHERRYWOOD 60 
#define AID_BOWSTRING_OF_THE_UNICORNS_MANE 61 
#define AID_ANGEL_FEATHER_ARROWS 62 
#define AID_BIRD_OF_PERCEPTION 63 
#define AID_STOIC_WATCHMAN 64 
#define AID_EMBLEM_OF_COGNIZANCE 65 
#define AID_STATESMANS_MEDAL 66 
#define AID_DIPLOMATS_RING 67 
#define AID_AMBASSADORS_SASH 68 
#define AID_RING_OF_THE_WAYFARER 69 
#define AID_EQUESTRIANS_GLOVES 70 
#define AID_NECKLACE_OF_OCEAN_GUIDANCE 71 
#define AID_ANGEL_WINGS 72 
#define AID_CHARM_OF_MANA 73 
#define AID_TALISMAN_OF_MANA 74 
#define AID_MYSTIC_ORB_OF_MANA 75 
#define AID_COLLAR_OF_CONJURING 76 
#define AID_RING_OF_CONJURING 77 
#define AID_CAPE_OF_CONJURING 78 
#define AID_ORB_OF_THE_FIRMAMENT 79 
#define AID_ORB_OF_SILT 80 
#define AID_ORB_OF_TEMPESTUOUS_FIRE 81 
#define AID_ORB_OF_DRIVING_RAIN 82 
#define AID_RECANTERS_CLOAK 83 
#define AID_SPIRIT_OF_OPPRESSION 84 
#define AID_HOURGLASS_OF_THE_EVIL_HOUR 85 
#define AID_TOME_OF_FIRE_MAGIC 86 
#define AID_TOME_OF_AIR_MAGIC 87 
#define AID_TOME_OF_WATER_MAGIC 88 
#define AID_TOME_OF_EARTH_MAGIC 89 
#define AID_BOOTS_OF_LEVITATION 90 
#define AID_GOLDEN_BOW 91 
#define AID_SPHERE_OF_PERMANENCE 92 
#define AID_ORB_OF_VULNERABILITY 93 
#define AID_RING_OF_VITALITY 94 
#define AID_RING_OF_LIFE 95 
#define AID_VIAL_OF_LIFEBLOOD 96 
#define AID_NECKLACE_OF_SWIFTNESS 97 
#define AID_BOOTS_OF_SPEED 98 
#define AID_CAPE_OF_VELOCITY 99 
#define AID_PENDANT_OF_DISPASSION 100 
#define AID_PENDANT_OF_SECOND_SIGHT 101 
#define AID_PENDANT_OF_HOLINESS 102 
#define AID_PENDANT_OF_LIFE 103 
#define AID_PENDANT_OF_DEATH 104 
#define AID_PENDANT_OF_FREE_WILL 105 
#define AID_PENDANT_OF_NEGATIVITY 106 
#define AID_PENDANT_OF_TOTAL_RECALL 107 
#define AID_PENDANT_OF_COURAGE 108 
#define AID_EVERFLOWING_CRYSTAL_CLOAK 109 
#define AID_RING_OF_INFINITE_GEMS 110 
#define AID_EVERPOURING_VIAL_OF_MERCURY 111 
#define AID_INEXHAUSTIBLE_CART_OF_ORE 112 
#define AID_EVERSMOKING_RING_OF_SULFUR 113 
#define AID_INEXHAUSTIBLE_CART_OF_LUMBER 114 
#define AID_ENDLESS_SACK_OF_GOLD 115 
#define AID_ENDLESS_BAG_OF_GOLD 116 
#define AID_ENDLESS_PURSE_OF_GOLD 117 
#define AID_LEGS_OF_LEGION 118 
#define AID_LOINS_OF_LEGION 119 
#define AID_TORSO_OF_LEGION 120 
#define AID_ARMS_OF_LEGION 121 
#define AID_HEAD_OF_LEGION 122 
#define AID_SEA_CAPTAINS_HAT 123 
#define AID_SPELLBINDERS_HAT 124 
#define AID_SHACKLES_OF_WAR 125 
#define AID_ORB_OF_INHIBITION 126 
#define AID_VIAL_OF_DRAGON_BLOOD 127 
#define AID_ARMAGEDDONS_BLADE 128 
#define AID_ANGELIC_ALLIANCE 129 
#define AID_CLOAK_OF_THE_UNDEAD_KING 130 
#define AID_ELIXIR_OF_LIFE 131 
#define AID_ARMOR_OF_THE_DAMNED 132 
#define AID_STATUE_OF_LEGION 133 
#define AID_POWER_OF_THE_DRAGON_FATHER 134 
#define AID_TITANS_THUNDER 135 
#define AID_ADMIRALS_HAT 136 
#define AID_BOW_OF_THE_SHARPSHOOTER 137 
#define AID_WIZARDS_WELL 138 
#define AID_RING_OF_THE_MAGI 139 
#define AID_CORNUCOPIA 140 
#define AID_DIPLOMATS_SUIT 141 
#define AID_MIRED_IN_NEUTRALITY 142 
#define AID_IRONFIST_OF_THE_OGRE 143 

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


// doll art slots
#define AS_HEAD    0
#define AS_SHOULDERS  1
#define AS_NECK    2
#define AS_RIGHT_HAND  3
#define AS_LEFT_HAND  4
#define AS_TORSO   5
#define AS_RIGHT_RING  6
#define AS_LEFT_RING  7
#define AS_FEET    8
#define AS_MISC_1   9
#define AS_MISC_2   10
#define AS_MISC_3   11
#define AS_MISC_4   12
#define AS_WAR_MACHINE_1 13
#define AS_WAR_MACHINE_2 14
#define AS_WAR_MACHINE_3 15
#define AS_WAR_MACHINE_4 16
#define AS_SPELL_BOOK  17
#define AS_MISC_5   18

#define AS_BALLISTA  AS_WAR_MACHINE_1
#define AS_AMMO_CART AS_WAR_MACHINE_2


/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

// Heros Second Skills
#define HSS_PATHFINDING 0
#define HSS_ARCHERY  1
#define HSS_LOGISTICS 2
#define HSS_SCOUTING 3
#define HSS_DIPLOMACY 4
#define HSS_NAVIGATION 5
#define HSS_LEADERSHIP 6
#define HSS_WISDOM  7
#define HSS_MYSTICISM 8
#define HSS_LUCK  9
#define HSS_BALLISTICS 10
#define HSS_EAGLE_EYE 11
#define HSS_NECROMANCY 12
#define HSS_ESTATES  13
#define HSS_FIRE_MAGIC 14
#define HSS_AIR_MAGIC 15
#define HSS_WATER_MAGIC 16
#define HSS_EARTH_MAGIC 17
#define HSS_SCHOLAR  18
#define HSS_TACTICS  19
#define HSS_ARTILLERY 20
#define HSS_LEARNING 21
#define HSS_OFFENCE  22
#define HSS_ARMORER  23
#define HSS_INTELLIGENCE 24
#define HSS_SORCERY  25
#define HSS_RESISTANCE 26
#define HSS_FIRST_AID 27


/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

//heroes ids
#define HID_ORRIN 0
#define HID_VALESKA 1
#define HID_EDRIC 2
#define HID_SYLVIA 3
#define HID_LORD_HAART 4
#define HID_SORSHA 5
#define HID_CHRISTIAN 6
#define HID_TYRIS 7
#define HID_RION 8
#define HID_ADELA 9
#define HID_CUTHBERT 10
#define HID_ADELAIDE
#define HID_INGHAM
#define HID_SANYA
#define HID_LOYNIS
#define HID_CAITLIN
#define HID_MEPHALA
#define HID_UFRETIN
#define HID_JENOVA
#define HID_RYLAND
#define HID_THORGRIM
#define HID_IVOR
#define HID_CLANCY
#define HID_KYRRE
#define HID_CORONIUS
#define HID_ULAND
#define HID_ELLESHAR
#define HID_GEM
#define HID_MALCOM
#define HID_MELODIA
#define HID_ALAGAR
#define HID_AERIS
#define HID_PIQUEDRAM
#define HID_THANE
#define HID_JOSEPHINE
#define HID_NEELA
#define HID_TOROSAR 
#define HID_FAFNER
#define HID_RISSA
#define HID_IONA
#define HID_ASTRAL
#define HID_HALON
#define HID_SERENA
#define HID_DAREMYTH
#define HID_THEODORUS
#define HID_SOLMYR
#define HID_CYRA
#define HID_AINE
#define HID_FIONA
#define HID_RASHKA
#define HID_MARIUS
#define HID_IGNATIUS
#define HID_OCTAVIA
#define HID_CALH
#define HID_PYRE
#define HID_NYMUS
#define HID_AYDEN
#define HID_XYRON
#define HID_AXSIS
#define HID_OLEMA
#define HID_CALID
#define HID_ASH
#define HID_ZYDAR
#define HID_XARFAX
#define HID_STRAKER
#define HID_VOKIAL
#define HID_MOANDOR
#define HID_CHARNA
#define HID_TAMIKA
#define HID_ISRA
#define HID_CLAVIUS
#define HID_GALTHRAN
#define HID_SEPTIENNA
#define HID_AISLINN
#define HID_SANDRO
#define HID_NIMBUS
#define HID_THANT
#define HID_XSI
#define HID_VIDOMINA
#define HID_NAGASH
#define HID_LORELEI
#define HID_ARLACH
#define HID_DACE
#define HID_AJIT
#define HID_DAMACON
#define HID_GUNNAR
#define HID_SYNCA
#define HID_SHAKTI
#define HID_ALAMAR
#define HID_JAEGAR
#define HID_MALEKITH
#define HID_JEDDITE
#define HID_GEON
#define HID_DEEMER
#define HID_SEPHINROTH
#define HID_DARKSTORN
#define HID_YOG
#define HID_GURNISSON
#define HID_JABARKAS
#define HID_SHIVA
#define HID_GRETCHIN
#define HID_KRELLION
#define HID_CRAG_HACK
#define HID_TYRAXOR
#define HID_GIRD
#define HID_VEY
#define HID_DESSA
#define HID_TEREK
#define HID_ZUBIN
#define HID_GUNDULA
#define HID_ORIS
#define HID_SAURUG
#define HID_BRON
#define HID_DRAKON
#define HID_WYSTAN
#define HID_TAZAR
#define HID_ALKIN
#define HID_KORBAC
#define HID_GERWULF
#define HID_BROGHILD
#define HID_MIRLANDA
#define HID_ROSIC
#define HID_VOY
#define HID_VERDISH
#define HID_MERIST
#define HID_STYG
#define HID_ANDRA
#define HID_TIVA
#define HID_PASIS
#define HID_THUNAR
#define HID_IGNISSA
#define HID_LACUS
#define HID_MONERE
#define HID_ERDAMON
#define HID_FIUR
#define HID_KALT
#define HID_LUNA
#define HID_BRISSA
#define HID_CIELE
#define HID_LABETHA
#define HID_INTEUS
#define HID_AENAIN
#define HID_GELARE
#define HID_GRINDAN
#define HID_SIR_MULLICH
#define HID_ADRIENNE
#define HID_CATHERINE
#define HID_DRACON
#define HID_GELU
#define HID_KILGOR
#define HID_LORD_HAART
#define HID_MUTARE
#define HID_ROLAND
#define HID_MUTARE_DRAKE
#define HID_BORAGUS
#define HID_XERON

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

// spells
#define SPL_SUMMON_BOAT  0
#define SPL_SCUTTLE_BOAT 1
#define SPL_VISIONS   2
#define SPL_VIEW_EARTH  3
#define SPL_DISGUISE  4
#define SPL_VIEW_AIR  5
#define SPL_FLY    6
#define SPL_WATER_WALK  7
#define SPL_DIMENSION_DOOR 8
#define SPL_TOWN_PORTAL  9

#define SPL_QUICKSAND  10
#define SPL_LAND_MINE  11
#define SPL_FORCE_FIELD  12
#define SPL_FIRE_WALL  13
#define SPL_EARTHQUAKE  14
#define SPL_MAGIC_ARROW  15
#define SPL_ICE_BOLT  16
#define SPL_LIGHTNING_BOLT 17
#define SPL_IMPLOSION  18
#define SPL_CHAIN_LIGHTNING 19
#define SPL_FROST_RING  20
#define SPL_FIREBALL  21
#define SPL_INFERNO   22
#define SPL_METEOR_SHOWER 23
#define SPL_DEATH RIPPLE 24
#define SPL_DESTROY_UNDEAD 25
#define SPL_ARMAGEDDON  26
#define SPL_SHIELD   27
#define SPL_AIR_SHIELD  28
#define SPL_FIRE_SHIELD  29
#define SPL_PROTECTION_FROM_AIR  30
#define SPL_PROTECTION_FROM_FIRE 31
#define SPL_PROTECTION_FROM_WATER 32
#define SPL_PROTECTION_FROM_EARTH 33
#define SPL_ANTI_MAGIC  34
#define SPL_DISPEL   35
#define SPL_MAGIC_MIRROR 36
#define SPL_CURE   37
#define SPL_RESURRECTION 38
#define SPL_ANIMATE_DEAD 39
#define SPL_SACRIFICE  40
#define SPL_BLESS   41
#define SPL_CURSE   42
#define SPL_BLOODLUST  43
#define SPL_PRECISION  44
#define SPL_WEAKNESS  45
#define SPL_STONE_SKIN  46
#define SPL_DISRUPTING_RAY 47
#define SPL_PRAYER   48
#define SPL_MIRTH   49
#define SPL_SORROW   50
#define SPL_FORTUNE   51
#define SPL_MISFORTUNE  52
#define SPL_HASTE   53
#define SPL_SLOW   54
#define SPL_SLAYER   55
#define SPL_FRENZY   56
#define SPL_TITANS_LIGHTNING_BOLT 57
#define SPL_COUNTERSTRIKE 58
#define SPL_BERSERK   59
#define SPL_HYPNOTIZE  60
#define SPL_FORGETFULNESS 61
#define SPL_BLIND   62
#define SPL_TELEPORT  63
#define SPL_REMOVE_OBSTACLE 64
#define SPL_CLONE   65
#define SPL_FIRE_ELEMENTAL 66
#define SPL_EARTH_ELEMENTAL 67
#define SPL_WATER_ELEMENTAL 68
#define SPL_AIR_ELEMENTAL 69

#define SPL_STONE   70 //443D3A 43E0EB 441B0D (!= 团 我? 屠 酪朗?
#define SPL_POISON   71
#define SPL_BIND   72
#define SPL_DESEASE   73
#define SPL_PARALYZE  74
#define SPL_AGING   75
#define SPL_DEATH_CLOUD  76
#define SPL_THUNDERBOLT  77
#define SPL_DISPEL   78
#define SPL_DEATH_STARE  79
#define SPL_ACID_BREATH  80

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

// spells flags
#define SPF_BATTLE    0x00000001 //- BF spell
#define SPF_MAP     0x00000002 //- MAP spell
#define SPF_TIME    0x00000004 //- Has a time scale (3 rounds or so)
#define SPF_CREATURE   0x00000008 //- Creature Spell
#define SPF_ON_STACK   0x00000010 //- target - single stack
#define SPF_ON_SHOOTING_STACK   0x00000020 //- target - single shooting stack (???)
#define SPF_HAS_MASS_ON_EXPERT 0x00000040 //- has a mass version at expert level
#define SPF_ON_LOCATION   0x00000080 //- target - any location
//0x00000100 - 
//0x00000200 - 
#define SPF_MIND    0x00000400 //- Mind spell
#define SPF_FRIENDLY_HAS_MASS   0x00000800 //- friendly and has mass version
#define SPF_NOT_ON_MACHINE  0x00001000 //- cannot be cast on SIEGE_WEAPON
#define SPF_ARTIFACT   0x00002000 //- Spell from Artifact
//0x00004000 -
//0x00008000 - AI 
//0x00010000 - AI area effect
//0x00020000 - AI
//0x00040000 - AI
//0x00080000 - AI number/ownership of stacks may be changed 
//0x00100000 - AI

// spells scool flags
#define SSF_AIR  1 
#define SSF_FIRE 2
#define SSF_WATER 4
#define SSF_EARTH 8
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

// battle creatures flags
#define BCF_2HEX_WIDE  0x00000001
#define BCF_CAN_FLY   0x00000002 // 脲蜞弪
#define BCF_CAN_SHOOT  0x00000004 // 耱疱?弪
#define BCF_2HEX_ATTACK  0x00000008 // 疣聒桊屙睇?疣滂篑 囹嚓?(磬 溻?觌弪觇)
#define BCF_ALIVE   0x00000010
#define BCF_CAN_ATTACK_WALL 0x00000020 // - 祛驽?疣琊篪囹?耱屙?
#define BCF_CANT_MOVE  0x00000040
#define BCF_KING_1   0x00000080 // KING_1
#define BCF_KING_2   0x00000100 // KING_2
#define BCF_KING_3   0x00000200 // KING_3
    // 00000400 - 0x0A ??? 00020000 + 40,41,83 - 礤 黧耱忤蝈脲??锺桴 囹嚓?
    // 00000800 - 0x0B 礤?铒桉囗? (35,74,75)
    // 00001000 - 0x0C ?犭桄礤?犷?狳弪 赅??溧朦礤?
    // 00002000 - 0x0D ----
    // 00004000 - 0x0E ??? IMMUNE_TO_FIRE_SPELLS
#define BCF_ATTACK_TWICE  0x00008000 // 囹嚓箦?溻噫潲
    // 00010000 - 0x10 囹嚓?徨?铗忮蜞
    // 32,33,56-69,112-117,120,121,123,,125,127,129,141,145-149 
#define BCF_UNDEAD   0x00040000 // 礤骅螯
    // 00080000 - 0x13 狳弪 怦艴 怵嚆钼 ?漕?
    // 00100000 - 0x14 疣聒桊屙睇?疣滂篑 耱疱?桴 栩钼
    // 00200000 - 0x15 耱 筢栩? 41E617 鬣痤溴?firebird - 祛驽?妁?赅耱钼囹?
#define BCF_CLONE   0x00800000
    // 01000000 - 0x18 汔痫梃-忮潼禧
    // 10000000 - 0x1C - 礤 祛驽?猁螯 疱耋疱牝屙 ???
    // 20000000 - 0x1D + 43DFAF
    // 40000000 - 0x1E + 43E06F
    // 80000000 - 0x1F 漯嚓铐



#define ATTACKER 0
#define DEFENDER 1



//main def group id
#define DG_MAIN 0

// battle monsters defs groups ids
#define BMDG_MOVE 0 // 理桁圉? 溻桄屙?
#define BMDG_RANDANIM 1
#define BMDG_STAY 2 // 理桁圉? 耱铋觇
#define BMDG_DAMAGE 3
#define BMDG_DEFENCE 4
#define BMDG_DEATH 5
#define BMDG_SPEC_DEATH 6
#define BMDG_TURN_TO_RIGHT_BEGIN 7 // 理桁圉? 磬鬣豚 镱忸痤蜞 怙疣忸
#define BMDG_TURN_TO_LEFT_END 8 // 理桁圉? 觐眦?镱忸痤蜞 怆邂?
#define BMDG_TURN_TO_LEFT_BEGIN 9 // 理桁圉? 磬鬣豚 镱忸痤蜞 怆邂?
#define BMDG_TURN_TO_RIGHT_END 10 // 理桁圉? 觐眦?镱忸痤蜞 怙疣忸
#define BMDG_HIT_UP 11
#define BMDG_HIT_STRAIGHT 12
#define BMDG_HIT_DOWN 13 // 理桁圉? 犭桄礤?囹嚓?忭桤
#define BMDG_SHOT_UP 14
#define BMDG_SHOT_STRAIGHT 15
#define BMDG_SHOT_DOWN 16 // 理桁圉? 溧朦礤?囹嚓?忭桤
#define BMDG_CAST_UP 17
#define BMDG_CAST_STRAIGHT 18
#define BMDG_CAST_DOWN 19 // 理桁圉? 觐脘铖蜮?忭桤
#define BMDG_BEGIN_MOVE 20 // 理桁圉? 磬鬣豚 溻桄屙?
#define BMDG_END_MOVE 21 // 理桁圉? 磬鬣豚 溻桄屙?


// ID 磬驵螓?觏铒铌
#define HK_ESC			1
#define HK_1			2
#define HK_2			3
#define HK_3			4
#define HK_4			5
#define HK_5			6
#define HK_6			7
#define HK_7			8
#define HK_8			9
#define HK_9			10
#define HK_0			11
#define HK_MINUS_1		12
#define HK_PLUS_1		13
#define HK_BACKSPACE	14
#define HK_CTRL			29
#define HK_LSHIFT		42
#define HK_RSHIFT		54

#define HK_SPACE	57

#define HK_ENTER	28

#define HK_F1		59
#define HK_F2		60
#define HK_F3		61
#define HK_F4		62
#define HK_F5		63
#define HK_F6		64
#define HK_F7		65
#define HK_F8		66
#define HK_F9		67
#define HK_F10		68

#define HK_B		48
#define HK_G		34
#define HK_S		31
#define HK_Q		16
#define HK_W		17