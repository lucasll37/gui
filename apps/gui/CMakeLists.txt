add_executable(meu_app_gui WIN32
  WinDXUT.cpp
  Window.cpp
  Input.cpp
  Engine.cpp
  App.cpp
  MyApp.cpp
  Resources.rc
)

target_link_libraries(meu_app_gui PRIVATE meu_app_core)

# Se estiver usando MinGW, o WIN32 às vezes já resolve;
# mas se precisar, força -mwindows:
if (MINGW)
  target_link_options(meu_app_gui PRIVATE -mwindows)
endif()

# Win32 MessageBox está em user32
if (MINGW OR MSVC)
  target_link_libraries(meu_app_gui PRIVATE user32)
endif()
