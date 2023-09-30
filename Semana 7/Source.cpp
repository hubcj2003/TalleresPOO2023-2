#include "Controlador.h"

void main() {
	Console::SetWindowSize(anchoConsola + 20, altoConsola);
	Console::CursorVisible = false;
	Controlador* controlador = new Controlador();
	controlador->jugar();
}