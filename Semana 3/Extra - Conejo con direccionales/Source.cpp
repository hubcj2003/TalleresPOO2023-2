#include "Conejo.h"
#include <conio.h>

void main() {
	Console::SetWindowSize(anchoConsola, altoConsola);
	Console::CursorVisible = false;
	srand(time(0));
	Conejo* conejo = new Conejo();
	time_t tiempoInicial = time(0);
	time_t tiempoFinal;
	do
	{
		tiempoFinal = time(0);
		Console::SetCursorPosition(2, 2);
		cout << "Tiempo : " << difftime(tiempoFinal, tiempoInicial);
		conejo->borrar();
		conejo->mover();
		conejo->dibujar();
		if (kbhit()) 
			conejo->direccion(getch());
		//else
		//	conejo->direccion(NULL);
		_sleep(50);
	} while (difftime(tiempoFinal, tiempoInicial) < 30);
}