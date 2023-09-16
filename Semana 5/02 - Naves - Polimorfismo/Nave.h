#pragma once
#include <iostream>
#include <conio.h>
#define anchoConsola 120
#define altoConsola 40
using namespace std;
using namespace System;
class Nave
{
public:
	Nave(int ancho, int alto);
	~Nave();
	void borrar();
	void mover();
	virtual void dibujar();
	int getDy();
	int getTipo();
protected:
	int x, y, ancho, alto, dx, dy, tipo;
};

Nave::Nave(int ancho, int alto)
{
	this->ancho = ancho;
	this->alto = alto;
	y = 0;
	dx = 0;
	dy = 1;
}

Nave::~Nave()
{
}

void Nave::borrar() {
	for (int i = 0; i < alto; i++)
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
}
void Nave::mover() {
	if (x + dx <0 || x + dx + ancho > anchoConsola)
		dx = -dx;
	if (y + dy <0 || y + dy + alto > altoConsola)
		dy = 0;
	x += dx;
	y += dy;
}

int  Nave::getDy() { return dy; }


void Nave::dibujar(){}

int  Nave::getTipo() { return tipo; }