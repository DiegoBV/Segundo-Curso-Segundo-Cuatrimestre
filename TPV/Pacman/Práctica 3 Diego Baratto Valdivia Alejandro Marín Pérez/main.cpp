//Alejandro Mar�n P�rez / Diego Baratto Valdivia (2� Videojuegos)
#include "SDLApp.h"
#include "Game.h"
#include "MainMenuState.h"
using namespace std;

int main(int argc, char* argv[]) {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SDLApp app;
	SDL_Event E;
	app.run();
	SDL_Quit();
	return 0;
}