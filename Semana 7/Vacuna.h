#pragma once
#include "Figura.h"
class Vacuna : public Figura
{
public:
	Vacuna();
	~Vacuna();
	void dibujar();
	void mover();
private:

};

Vacuna::Vacuna()
{
	tipo = "vacuna";
	Random r;
	alto = 1;
	ancho = 4;
	x = r.Next(0, anchoConsola - ancho);
	y = r.Next(0, altoConsola - alto);
	do
	{
		dx = r.Next(-1, 2); //-1 0 1
		dy = r.Next(-1, 2); //-1 0 1
	} while (abs(dx) == abs(dy));
	dx *= 2;
}

Vacuna::~Vacuna()
{
}

void Vacuna::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "|->|";
}

void Vacuna::mover() {
	movimiento(-dx, -dy);
}