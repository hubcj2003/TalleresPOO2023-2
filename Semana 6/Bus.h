#pragma once
#include "Terrestre.h"
class Bus : public Terrestre
{
public:
	Bus();
	~Bus();
	void dibujar();
	void mover();
private:

};

Bus::Bus() : Terrestre(13, 3)
{
	tipo = 'B';
	x = anchoConsola - 13;
	dx = -2;
}

Bus::~Bus()
{
}

void Bus::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "_/_|[][][][]|";
	Console::SetCursorPosition(x, y + 1);
	cout << "[           |";
	Console::SetCursorPosition(x, y + 2);
	cout << "=--OO---OO-=";
}

void Bus::mover() {
	Random r;
	dx = -r.Next(3, 6);
	validarMovimiento(0, 0);
}