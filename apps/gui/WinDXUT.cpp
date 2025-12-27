#include "DXUT.h"

// // #include <meu_app/core.hpp>

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nCmdShow
)

{
    Window * window = new Window();
    window->Mode(WINDOWED);
    window->Size(1024, 600);
    window->Color(0, 122, 204);
    window->Title("Aplicação");
    window->Icon(IDI_APP_ICON);
    window->Cursor(IDC_APP_CURSOR);
    window->Create();

    MSG message;

    while (GetMessage(&message, NULL, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    delete window;
    return 0;
}