#pragma once
#include <iostream>
#define anchoConsola 100
#define altoConsola 30

using namespace std;
using namespace System;

class Figura
{
public:
	Figura();
	~Figura();
	void movimiento(int pdx, int pdy);
	void borrar();
	virtual void dibujar();
	virtual void mover();
	bool colision(int ex, int ey, int eancho, int ealto);
	int getX();
	int getY();
	int getAncho();
	int getAlto();
	string getTipo();
protected:
	int x, y, dx, dy, ancho, alto;
	string tipo;
};

Figura::Figura()
{

}

Figura::~Figura()
{
}

void Figura::movimiento(int pdx, int pdy) {
	if (x + dx < 0 || x + dx + ancho > anchoConsola)
		dx = pdx;
	if (y + dy < 0 || y + dy + alto > altoConsola)
		dy = pdy;
	x += dx;
	y += dy;
}
void Figura::borrar() {
	for (int i = 0; i < alto; i++)
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
}
void Figura::dibujar() {}
void Figura::mover() {}
bool Figura::colision(int ex, int ey, int eancho, int ealto) {
	return x <= ex + eancho && ex <= x + ancho && y <= ey + ealto && ey <= y + alto;
}

int Figura::getX() { return x; }
int Figura::getY() { return y; }
int Figura::getAncho() { return ancho; }
int Figura::getAlto() { return alto; }
string  Figura::getTipo() { return tipo; }