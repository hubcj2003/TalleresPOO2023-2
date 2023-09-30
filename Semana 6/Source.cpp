#include "Juego.h"

void main() {
	Console::SetWindowSize(anchoConsola, altoConsola);
	Console::CursorVisible = false;
	srand(time(0));
	Juego* juego = new Juego();
	juego->jugar();
}