#include "Controladora.h"

void main() {
	Console::SetWindowSize(anchoConsola, altoConsola);
	Console::CursorVisible = false;
	srand(time(0));
	Controladora* controladora = new Controladora();
	controladora->jugar();
}