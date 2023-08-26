#pragma once
#include <iostream>
#define anchoConsola 80
#define altoConsola 25

using namespace std;
using namespace System;
class Triangulo
{
public:
	Triangulo();
	Triangulo(int px, int py, int palto, int pancho, int pdx, int pdy);
	~Triangulo();
	void dibujar();
	void mover();
	void borrar();
private:
	int x, y, ancho, alto, dx, dy, tipo;
};

Triangulo::Triangulo()
{
	ancho = alto = 4 + rand() % 4;
	dx = rand() % 2 * 2 - 1; 
	x = rand() % (anchoConsola - ancho);
	y = rand() % (altoConsola - alto);
	dy = 0;
	tipo = rand() % 2;
}

Triangulo::Triangulo(int px, int py, int palto, int pancho, int pdx, int pdy)
{
	x = px;
	y = py;
	ancho = pancho;
	alto = palto;
	dx = pdx;
	dy = pdy;
	tipo = rand() % 2;
}

Triangulo::~Triangulo()
{
}

void Triangulo::dibujar(){
	if (tipo) {
		for (int i = 1; i <= alto; i++) {
			Console::SetCursorPosition(x, y + i - 1);
			for (int j = 1; j <= i; j++)
				if (i == alto || j == 1 || i == j)
					cout << "*";
				else
					cout << " ";
		}
	}
	else {
		for (int i = 1; i <= alto; i++) {
			Console::SetCursorPosition(x, y + i - 1);
			for (int j = 1; j <= ancho; j++)
				if (i == 1 || j == ancho || i == j)
					cout << "*";
				else
					cout << " ";
		}
	}
}
void Triangulo::mover(){
	if (x + dx < 0 || x + ancho + dx > anchoConsola)
		dx = -dx;
	if (y + dy < 0 || y + alto + dy > altoConsola)
		dy = -dy;
	x += dx;
	y = y + dy;
}
void Triangulo::borrar(){
	for (int i = 0; i < alto; i++)
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
}