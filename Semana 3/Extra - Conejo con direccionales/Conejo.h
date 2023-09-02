#pragma once
#include <iostream>
#define anchoConsola 100 //80
#define altoConsola 30 //25
#define izquierda 75
#define derecha 77
#define arriba 72
#define abajo 80

using namespace std;
using namespace System;

class Conejo
{
public:
	Conejo();
	~Conejo();
	void dibujar();
	void mover();
	void borrar();
	void direccion(char tecla);
private:
	int x, y, dx, dy, ancho, alto;
	ConsoleColor color;
};

Conejo::Conejo()
{
	alto = 4;
	ancho = 5;
	x = rand() % (anchoConsola - ancho);
	y = rand() % (altoConsola - alto);
	dx = dy = 0;
	color = ConsoleColor(rand() % 16);
}

Conejo::~Conejo()
{
}

void Conejo::dibujar(){
	Console::ForegroundColor = color;
	if (dx > 0) {
		Console::SetCursorPosition(x, y);
		cout << " //  ";
		Console::SetCursorPosition(x, y + 1);
		cout << " ('> ";
		Console::SetCursorPosition(x, y + 2);
		cout << " /rr ";
		Console::SetCursorPosition(x, y + 3);
		cout << "*\\))_";
	}
	else {
		Console::SetCursorPosition(x, y);
		cout << " \\\\";
		Console::SetCursorPosition(x, y + 1);
		cout << " <' )";
		Console::SetCursorPosition(x, y + 2);
		cout << " rr\\ ";
		Console::SetCursorPosition(x, y + 3);
		cout << "_((/*";
	}
	Console::ForegroundColor = ConsoleColor::Gray;
}
void Conejo::mover(){
	if (x + dx< 0 || x + dx + ancho > anchoConsola)
		dx = 0;
	if (y + dy< 0 || y + dy + alto > altoConsola)
		dy = 0;
	x += dx;
	y += dy;
}
void Conejo::borrar(){
	for (int i = 0; i < alto; i++)
		for (int j= 0; j < ancho; j++)	{
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
}
void Conejo::direccion(char tecla) {
	dx = dy = 0;
	switch (tecla)
	{
	case arriba: dy = -1; break;
	case abajo: dy = 1; break;
	case izquierda: dx = -2; break;
	case derecha: dx = 2; break;
	}
}