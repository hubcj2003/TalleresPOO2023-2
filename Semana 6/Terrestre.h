#pragma once
#include <iostream>
#define anchoConsola 120
#define altoConsola 30

using namespace std;
using namespace System;

class Terrestre
{
public:
	Terrestre(int pancho, int palto);
	~Terrestre();
	void validarMovimiento(int pdx, int pdy);
	void borrar();
	virtual void mover() = 0;
	virtual void dibujar();
	bool colision(int ex, int ey, int eancho, int ealto);
	int getX();
	int getY();
	int getDX();
	int getDY();
	int getAncho();
	int getAlto();
	int getTipo();
protected:
	int x, y, dx, dy, ancho, alto;
	char tipo;
};

Terrestre::Terrestre(int pancho, int palto)
{
	ancho = pancho;
	alto = palto;
	y = rand() % (altoConsola - alto - 3);
	dy = 0;
}

Terrestre::~Terrestre()
{
}

void Terrestre::validarMovimiento(int pdx, int pdy) {
	if (x + dx < 0 || x + dx + ancho > anchoConsola)
		dx = pdx;
	if (y + dy < 0 || y + dy + alto> altoConsola)
		dy = pdy;
	x += dx;
	y += dy;
}
void Terrestre::borrar() {
	for (int i = 0; i < alto; i++)
		for (int j = 0; j < ancho; j++)	{
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
}
void Terrestre::dibujar() {}

bool Terrestre::colision(int ex, int ey, int eancho, int ealto) {
	return x < ex + eancho && ex < x + ancho 
		&& y < ey + ealto && ey < y + alto;
}

int Terrestre::getX() { return x; }
int Terrestre::getY() { return y; }
int Terrestre::getDX() { return dx; }
int Terrestre::getDY() { return dy; }
int Terrestre::getAncho() { return ancho; }
int Terrestre::getAlto() { return alto; }
int Terrestre::getTipo() { return tipo; }