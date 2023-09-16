#pragma once
#include "Alfa.h"
#include "Beta.h"
#include "Gamma.h"
#include <vector>
class Controladora
{
public:
	Controladora();
	~Controladora();
	void jugar();
	void mover();
	void borrar();
	void dibujar();
	void eliminar();
private:
	vector<Nave*> naves;
	int cA, cB;
};

Controladora::Controladora()
{
	cA = cB = 0;
}

Controladora::~Controladora()
{
}

void Controladora::jugar() {
	string mensaje = "comienza la invasión...!!!";
	Console::SetCursorPosition((anchoConsola - mensaje.size()) / 2, 20);
	cout << mensaje;
	_sleep(100);
	Console::Clear();
	do
	{
		if (kbhit())
			if (toupper(getch()) == 'A') {
				naves.push_back(new Alfa());
				cA++;
			}
		if (cA == 2) {
			naves.push_back(new Beta());
			cA = 0;
			cB++;
		}
		if (cB == 2) {
			naves.push_back(new Gamma());
			cB = 0;
		}
		if (naves.size() > 20) {
			Console::Clear();
			mensaje = "Hemos sido invadidos...";
			Console::SetCursorPosition((anchoConsola - mensaje.size()) / 2, 20);
			cout << mensaje;
			getch();
			getch();
			getch();
			getch();
			break;
		}
		borrar();
		mover();
		dibujar();
		eliminar();
		_sleep(150);
	} while (true);
}
void Controladora::mover() {
	for (int i = 0; i < naves.size(); i++)
		naves[i]->mover();
}
void Controladora::borrar() {
	for (int i = 0; i < naves.size(); i++)
		naves[i]->borrar();
}
void Controladora::dibujar() {
	for (int i = 0; i < naves.size(); i++)
		naves[i]->dibujar();

}

void Controladora::eliminar() {
	for (int i = 0; i < naves.size(); i++)
		if (naves[i]->getDy() == 0) {
			naves[i]->borrar();
			naves.erase(naves.begin() + i);
			i--;
		}
}