#pragma once
#include <iostream>
#include <conio.h>
#define anchoConsola 120
#define altoConsola 40
using namespace std;
using namespace System;
class Avion
{
public:
	Avion(int ancho, int alto);
	~Avion();
	void borrar();
	void mover();
protected:
	int x, y, ancho, alto, dx, dy;
};

Avion::Avion(int ancho, int alto)
{
	this->ancho = ancho;
	this->alto = alto;
	x = rand() % (anchoConsola - ancho);
	y = rand() % (altoConsola - alto);
	dx = (rand() % 2 * 2 - 1) * 2;
	dy = rand() % 2 * 2 - 1;
}

Avion::~Avion()
{
}

void Avion::borrar() {
	for (int i = 0; i < alto; i++)
		for (int j = 0; j < ancho; j++)	{
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
}
void Avion::mover() {
	if (x + dx <0 || x + dx + ancho > anchoConsola)
		dx = -dx;
	if (y + dy <0 || y + dy + alto > altoConsola)
		dy = -dy;
	x += dx;
	y += dy;
}