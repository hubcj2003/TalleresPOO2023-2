#pragma once
#include <iostream>
#define anchoConsola 100
#define altoConsola 30
using namespace std;
using namespace System;
class Fantasma
{
public:
	Fantasma();
	~Fantasma();
	void mover();
	void dibujar();
	void borrar();
private:
	int x, y, dx, dy, ancho, alto;
};

Fantasma::Fantasma()
{
	ancho = 11;
	alto = 8;
	//dx = (rand() % 2 * 2 - 1) * 2; //SI QUIERO MOVER DE DOS EN DOS O DE MAS
	dx = rand() % 2 * 2 - 1;
	dy = rand() % 2 * 2 - 1;
	x = rand() % (anchoConsola - ancho);
	y = rand() % (altoConsola - alto);
}

Fantasma::~Fantasma()
{
}
void Fantasma::mover() {
	if (x + dx < 0 || x + dx + ancho > anchoConsola)
		dx = -dx;
	if (y + dy < 0 || y + dy + alto > altoConsola)
		dy = -dy;
	x += dx;
	y += dy;
}
void Fantasma::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "    .-.";
	Console::SetCursorPosition(x, y + 1);
	cout << "   ( \" )";
	Console::SetCursorPosition(x, y + 2);
	cout << "/\\_.' '._/\\";
	Console::SetCursorPosition(x, y + 3);
	cout << "|         |";
	Console::SetCursorPosition(x, y + 4);
	cout << " \\       /";
	Console::SetCursorPosition(x, y + 5);
	cout << "  \\     /`";
	Console::SetCursorPosition(x, y + 6);
	cout << "   (__) /";
	Console::SetCursorPosition(x, y + 7);
	cout << "   `.__.'";

}
void Fantasma::borrar() {
	for (int i = 0; i < alto; i++)
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
}