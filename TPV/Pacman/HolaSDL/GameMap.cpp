#include "GameMap.h"
#include "Game.h"


GameMap::GameMap() //Crea un tablero con un array din�mico
{	
}
GameMap::GameMap(int fils, int cols, Texture* vit, Texture* m, Texture* com, Game* gam) { //Constructora con par�metros
	textsMapa[0] = m;
	textsMapa[1] = com; //asignacion de punteros
	textsMapa[2] = vit;
	game = gam;
	if (fils != 0 && cols != 0) {
		this->fils = fils;
		this->cols = cols;

		//Creaci�n de la matriz
		tablero = new MapCell*[fils]; //Es una matriz de punteros, para referenciar las casillas
		for (int r = 0; r < fils; r++) {
			tablero[r] = new MapCell[cols]; //Ahora s� son arrays din�micos completos
		}
	}
	else {
		tablero = nullptr;
	}
}

GameMap::~GameMap()  //Destructora por defecto del tablero de juego, destruye el array din�mico
{
	if (tablero != nullptr) {
		for (int r = 0; r < fils; r++) {
			delete[] tablero[r];
		}
		delete[] tablero;
	}
}
MapCell GameMap::getCell(int fils, int cols) {
	if (fils < game->dame_FilasTablero() && fils >= 0 && cols < game->dame_ColumnasTablero() && cols >= 0) 
		return tablero[fils][cols];
}

void GameMap::modifica_Posicion(int x, int y, MapCell nuevoObjeto) {
	tablero[x][y] = nuevoObjeto;
}

void GameMap::render() {
	for (int i = 0; i < fils; i++) {
		for (int j = 0; j < cols; j++) {
			SDL_Rect des;
			des.x = j * game->dame_Anchura() / cols;
			des.y = i * game->dame_Altura() / fils;
			des.w = game->dame_Anchura() / cols;
			des.h = game->dame_Altura() / fils;
			if ((int)tablero[i][j] > 0) {
				textsMapa[(int)tablero[i][j] - 1]->RenderFrame(game->dame_Renderer(), des); //para ahorrarse el switch, cambiamos a entero la pos del 
				//tablero y le mandamos que haga render
			}
		}
	}
}

void GameMap::loadFromFile(ifstream& file) {
	if (file.is_open()) {
		game->filasTablero = fils;
		game->colsTablero = cols;
		for (int i = 0; i < fils; i++) {
			for (int j = 0; j < cols; j++) {
				int pos;
				file >> pos;
				this->modifica_Posicion(i, j, (MapCell)pos);
				if (pos == 2 || pos == 3) {
					game->setComida(1); //si es comida o vitamina aumentamos en 1 el numComida
				}
			}
		}
		/*archivo >> levels_Index; //si existe, se guarda el nivel en que nos quedamos
		archivo.close();*/
	}
}

void GameMap::saveToFile(ofstream& file) {
	file << this->fils << " " << this->cols << endl;
	for (int i = 0; i < fils; i++) {
		for (int j = 0; j < cols; j++) {
			file << (int)this->getCell(i, j) << " ";
		}
		file << endl;
	}
}

void GameMap::render(bool) {
}

void GameMap::update() {
}