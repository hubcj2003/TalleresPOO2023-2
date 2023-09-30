#pragma once
#include "Terrestre.h"
#define izquierda 75
#define derecha 77
#define arriba 72
#define abajo 80
class Persona : public Terrestre
{
public:
	Persona();
	~Persona();
	void dibujar();
	void mover();
	void direccion(char tecla);
private:
};

Persona::Persona() : Terrestre(1, 2)
{
	y = altoConsola - 2;
	x = anchoConsola / 2;
	dx = 0;
	dy = 0;
}

Persona::~Persona()
{
}

void Persona::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "0";
	Console::SetCursorPosition(x, y + 1);
	cout << "+";
}

void Persona::mover() {
	validarMovimiento(0, 0);
}

void Persona::direccion(char tecla) {
	dx = dy = 0;
	switch (tecla)
	{
	case arriba: dy = -1; break;
	case abajo: dy = 1; break;
	case izquierda: dx = -2; break;
	case derecha: dx = 2; break;
	}
}