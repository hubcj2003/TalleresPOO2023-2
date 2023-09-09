#pragma once
#include <iostream>
#define anchoConsola 100
#define altoConsola 30
#define izquierda 75
#define derecha 77
#define arriba 72
#define abajo 80
using namespace std;
using namespace System;
class Monigote
{
public:
	Monigote();
	~Monigote();
	void mover();
	void dibujar();
	void borrar();
	void direccion(char tecla);
	bool colision(int ex, int ey, int eancho, int ealto);
private:
	int x, y, dx, dy, ancho, alto;
};

Monigote::Monigote()
{
	ancho = 1;
	alto = 2;
	dx = dy = 0;
	x = rand() % (anchoConsola - ancho);
	y = rand() % (altoConsola - alto);
}

Monigote::~Monigote()
{
}
void Monigote::mover() {
	if (x + dx < 0 || x + dx + ancho > anchoConsola)
		dx = 0;
	if (y + dy < 0 || y + dy + alto > altoConsola)
		dy = 0;
	x += dx;
	y += dy;
}
void Monigote::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "0";
	Console::SetCursorPosition(x, y + 1);
	cout << "┼";

}
void Monigote::borrar() {
	for (int i = 0; i < alto; i++)
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
}

void Monigote::direccion(char tecla) {
	dx = dy = 0;
	switch (tecla)
	{
	case izquierda: dx = - 2; break;
	case derecha: dx =  2; break;
	case arriba: dy =  -1; break;
	case abajo: dy =  1; break;
	}
}

bool Monigote::colision(int ex, int ey, int eancho, int ealto) {
	return x < ex + eancho && ex < x + ancho 
		&& y < ey + ealto && ey < y + alto;
}