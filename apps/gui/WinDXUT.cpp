#include <sstream>
#include "DXUT.h"

using std::stringstream;

Window window; // = Window();
void Welcome();
void Bye();

// // #include <meu_app/core.hpp>

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nCmdShow
)

{
    window = Window();
    window.Mode(WINDOWED);
    window.Size(1024, 600);
    window.Color(0, 122, 204);
    window.Title("Aplicação");
    window.Icon(IDI_APP_ICON);
    // window.Cursor(IDC_APP_CURSOR);

    window.InFocus(Welcome);
    window.LostFocus(Bye);
    window.Create();

    Input input = Input();
    MSG message;
    stringstream text;

    int x = window.CenterX();
    int y = window.CenterY();

    // window.Print("Teste de Capctura de Teclas", x - 110, y - 150, RGB(255, 255, 255));

    while (GetMessage(&message, NULL, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessage(&message);


        if(input.KeyPress(VK_ESCAPE)) {
            window.Close();
        }
        
        if(input.KeyDown(VK_CONTROL)) {
            window.Print("CTRL", x-125, y+150, RGB(255, 255, 255));
        }

        if(input.KeyDown(VK_RETURN)) {
            window.Print("ENTER", x-25, y+150, RGB(255, 255, 255));
        }

        if(input.KeyDown(VK_SPACE)) {
            window.Print("SPACE", x+75, y+150, RGB(255, 255, 255));
        }


        if(input.KeyPress('R')) {
            window.Clear();
            window.Print("Teste de Capctura de Teclas", x - 110, y - 150, RGB(255, 255, 255));
        }

        text.str("");
        text << input.MouseX() << " x " << input.MouseY();

        if(input.KeyDown(VK_LBUTTON)) {
            window.Clear();
            window.Print("Botão Esquerdo", x-45, y-230, RGB(255, 255, 255));
            window.Print(text.str().c_str(), x-32, y-210, RGB(255, 255, 255));
        }

        if(input.KeyDown(VK_MBUTTON)) {
            window.Clear();
            window.Print("Botão Meio", x-50, y-230, RGB(255, 255, 255));
            window.Print(text.str().c_str(), x-32, y-210, RGB(255, 255, 255));
        }

        if(input.KeyDown(VK_RBUTTON)) {
            window.Clear();
            window.Print("Botão Direito", x-45, y-230, RGB(255, 255, 255));
            window.Print(text.str().c_str(), x-32, y-210, RGB(255, 255, 255));
        }

        short rotation = input.MouseWheel();

        if(rotation != 0) {
            window.Clear();
            window.Print("ROLAGEM", x-35, y-250, RGB(255, 255, 255));

            if(rotation > 0) {
                window.Print("ROLAGEM", x-52, y-230, RGB(255, 255, 255));
            }
            else {
                window.Print("ROLAGEM", x-40, y-230, RGB(255, 255, 255));
            }

            text.str("");
            text << rotation;
            window.Print(text.str().c_str(), x-8, y-210, RGB(255, 255, 255));
        }

        if(input.KeyPress(VK_INSERT)) {
            input.Read();
        }
        
        window.Print(Input::Text(), x-120 , y-120, RGB(255, 255, 255));

    }

    return 0;
}

void Welcome() {
    window.Clear();
    window.Print("De volta?", 485, 300, RGB(255, 255, 255));
}

void Bye() {
    window.Clear();
    window.Print("Até logo!", 485, 300, RGB(255, 255, 255));   
}