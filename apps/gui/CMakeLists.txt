add_executable(meu_app_gui WIN32
  TimerDXUT.cpp
  App.cpp
  Engine.cpp
  Input.cpp
  Timer.cpp
  Window.cpp
  Resources.rc
)

# ========================================
# Configurações de Encoding UTF-8
# ========================================
if(MINGW)
  target_compile_options(meu_app_gui PRIVATE 
    -finput-charset=UTF-8 
    -fexec-charset=UTF-8
  )
endif()

# ========================================
# Configurações de Debug/Release
# ========================================
if(MINGW)
  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Em Debug: mostra console para printf/cout
    target_link_options(meu_app_gui PRIVATE -mconsole)
    message(STATUS "   → Console de debug ativado para meu_app_gui")
  else()
    # Em Release: esconde console
    target_link_options(meu_app_gui PRIVATE -mwindows)
  endif()
endif()

# ========================================
# Bibliotecas
# ========================================
target_link_libraries(meu_app_gui PRIVATE 
  meu_app_core
)

# Win32 APIs necessárias
if(MINGW OR MSVC)
  target_link_libraries(meu_app_gui PRIVATE 
    user32
    gdi32
  )
endif()

# add_executable(meu_app_gui WIN32
# TimerDXUT.cpp
#   App.cpp
#   Engine.cpp
#   Input.cpp
#   Timer.cpp
#   Window.cpp
#   Resources.rc
# )

# target_link_libraries(meu_app_gui PRIVATE meu_app_core)

# # Se estiver usando MinGW, o WIN32 às vezes já resolve;
# # mas se precisar, força -mwindows:
# if (MINGW)
#   target_link_options(meu_app_gui PRIVATE -mwindows)
# endif()

# # Win32 MessageBox está em user32
# if (MINGW OR MSVC)
#   target_link_libraries(meu_app_gui PRIVATE user32)
# endif()
