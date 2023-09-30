#pragma once
#include "Terrestre.h"
class Bicicleta : public Terrestre
{
public:
	Bicicleta();
	~Bicicleta();
	void dibujar();
	void mover();
private:

};

Bicicleta::Bicicleta() : Terrestre(6, 2)
{
	Random r;
	tipo = 'I';
	x = r.Next(anchoConsola - 6);
	dx = r.Next(2) * 2 - 1;
}

Bicicleta::~Bicicleta()
{
}

void Bicicleta::dibujar() {
	if (dx < 0) {
		Console::SetCursorPosition(x, y);
		cout << "/_..";
		Console::SetCursorPosition(x, y + 1);
		cout << "(o)(o)";
	}
	else {
		Console::SetCursorPosition(x, y);
		cout << ".._\\";
		Console::SetCursorPosition(x, y + 1);
		cout << "(o)(o)";
	}
}

void Bicicleta::mover() {
	validarMovimiento(-dx, 0);
}