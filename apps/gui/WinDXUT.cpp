
#include <locale>
#include <clocale>
#include "DXUT.h"
#include "MyApp.h"

// // #include <meu_app/core.hpp>

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nCmdShow
) {

    std::setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleOutputCP(CP_UTF8);

    MyApp* app = new MyApp();
    Engine* engine = new Engine();

    engine->window->Mode(WINDOWED);
    engine->window->Size(1024, 600);
    engine->window->Color(0, 122, 204);
    engine->window->Title("Aplicação");
    engine->window->Icon(IDI_APP_ICON);
    // engine.window->Cursor(IDC_APP_CURSOR);

    int exitCode = engine->Start(app);

    delete app;
    delete engine;

    return exitCode;
}