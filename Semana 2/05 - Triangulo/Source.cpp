#include "Triangulo.h"
#include <vector>
#include <conio.h>

void main() {
	srand(time(0));
	Console::SetWindowSize(anchoConsola, altoConsola);
	vector<Triangulo*> triangulos;
	triangulos.push_back(new Triangulo(10, 12, 5, 5, 3, 0));
	triangulos.push_back(new Triangulo(60, 2, 7, 7,0, 1));
	do
	{
		for (int i = 0; i < triangulos.size(); i++)	{
			triangulos[i]->borrar();
			triangulos[i]->mover();
			triangulos[i]->dibujar();
		}
		_sleep(100);
	} while (!(kbhit()));
	cout << "Terminaste" << endl;
	getch();
	getch();
}