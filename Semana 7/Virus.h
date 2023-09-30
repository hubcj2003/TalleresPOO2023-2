#pragma once
#include "Figura.h"
class Virus : public Figura
{
public:
	Virus();
	~Virus();
	void dibujar();
	void mover();
private:

};

Virus::Virus()
{
	tipo = "virus";
	Random r;
	alto = 5;
	ancho = 9;
	x = r.Next(0, anchoConsola - ancho);
	y = r.Next(0, altoConsola - alto);
	do
	{
		dx = r.Next(-4, 5); //[-5 -4 -3- 2 -1 0 1 2 3 4 5]
		dy = r.Next(-2, 3); //-3 0 3
		_sleep(10);
	} while (dx == 0 || dy == 0);
}

Virus::~Virus()
{
}

void Virus::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "    q";
	Console::SetCursorPosition(x, y + 1);
	cout << "  0-0-0";
	Console::SetCursorPosition(x, y + 2);
	cout << "0-0 0 0-0";
	Console::SetCursorPosition(x, y + 3);
	cout << "  0-0-0";
	Console::SetCursorPosition(x, y + 4);
	cout << "    b";
}

void Virus::mover() {
	movimiento(-dx, -dy);
}