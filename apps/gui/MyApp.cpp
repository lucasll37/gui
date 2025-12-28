#include "MyApp.h"

void MyApp::Init() {
    lastX = input->MouseX();
    lastY = input->MouseY();

    textSize << "Tamanho: " << window->Width() << " x " << window->Height();
    textMode << "Formato " << (window->Mode() == WINDOWED ? "Em Janela" : "Tela Cheia");
    textMouse << input->MouseX() << " x " << input->MouseY();
}

void MyApp::Update() {
    if(input->KeyPress(VK_ESCAPE)) {
        window->Close();
    }

    textMouse.str("");
    textMouse << input->MouseX() << " x " << input->MouseY();


    if(lastX != input->MouseX() || lastY != input->MouseY()) {
        window->Clear();
        Display();
    }

    lastX = input->MouseX();
    lastY = input->MouseY();
}


void MyApp::Display() {
    window->Print("Window App Demo", 10 , 10, RGB(255, 255, 255));
    window->Print(textSize.str(), 10 , 50, RGB(255, 255, 255));
    window->Print(textMode.str(), 10 , 75, RGB(255, 255, 255));
    window->Print(textMouse.str(), 10 , 100, RGB(255, 255, 255));
}

void MyApp::Finalize() {}
