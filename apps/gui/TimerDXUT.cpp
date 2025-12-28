/**********************************************************************************
// TimerDXUT (C�digo Fonte)
//
// Cria��o:		16 Jan 2020
// Atualiza��o:	31 Jul 2021
// Compilador:	Visual C++ 2019
//
// Descri��o:	Testa as funcionalidades de anima��o do motor DXUT
//
**********************************************************************************/

#include "DXUT.h"

// ------------------------------------------------------------------------------

class WinApp : public App
{
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();	
};

// ------------------------------------------------------------------------------

void WinApp::Init()
{

}

// ------------------------------------------------------------------------------

void WinApp::Update()
{
	// sai com o pressionamento da tecla ESC
	if (input->KeyPress(VK_ESCAPE))
		window->Close();
}

// ------------------------------------------------------------------------------

void WinApp::Draw()
{
	
}

// ------------------------------------------------------------------------------

void WinApp::Finalize()
{
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	                 LPSTR lpCmdLine, int nCmdShow)
{
	// cria motor e configura a janela
	Engine* engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(1024, 600);
	engine->window->Color(0, 122, 204);
	engine->window->Title("Timer DXUT");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e executa a aplica��o
	int exitCode = engine->Start(new WinApp());

	// finaliza execu��o
	delete engine;
	return exitCode;
}

// ----------------------------------------------------------------------------

