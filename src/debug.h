// Debugging macros
#define DEBUG 0
#define DEBUG_WS 0
#if DEBUG || DEBUG_WS
  #define DEBUG_PORT Serial
#endif /* DEBUG || DEBUG_WS */
#if DEBUG
  #define DEBUG_GRANDEUR(format, args...) \
      DEBUG_PORT.printf(("[GRANDEUR-DEBUG] " + String(format) + "\n").c_str(), ##args)
  #else
  //#define DEBUG_GRANDEUR(format, args...) \
    os_printf(("[GRANDEUR-DEBUG] " + String(format)).c_str(), ##args)

  #ifndef DEBUG_GRANDEUR
  #define DEBUG_GRANDEUR(format, args...)
  #endif
#endif /* DEBUG */