#pragma once
#include <iostream>
#define anchoConsola 100
#define altoConsola 30
using namespace std;
using namespace System;
class Corazon
{
public:
	Corazon();
	~Corazon();
	void dibujar();
	void borrar();
	int getx();
	int gety();
	int getancho();
	int getalto();
private:
	int x, y, ancho, alto;
};

Corazon::Corazon()
{
	ancho = 1;
	alto = 1;
	x = rand() % (anchoConsola - ancho);
	y = rand() % (altoConsola - alto);
}

Corazon::~Corazon()
{
}
void Corazon::dibujar() {
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(x, y);
	cout << char(3);
	Console::ForegroundColor = ConsoleColor::Gray;
}
void Corazon::borrar() {
	for (int i = 0; i < alto; i++)
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
}

int Corazon::getx() { return x; }
int Corazon::gety() { return y; }
int Corazon::getancho() { return ancho; }
int Corazon::getalto() { return alto; }