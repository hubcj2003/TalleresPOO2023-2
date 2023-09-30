#pragma once
#include "Terrestre.h"
class Carro : public Terrestre
{
public:
	Carro();
	~Carro();
	void dibujar();
	void mover();
private:

};															
															
Carro::Carro() : Terrestre(8, 3)							
{															
	tipo = 'C';
	x = 0;
	dx = 2;
}															
															
Carro::~Carro()												
{															
}															
															
void Carro::dibujar() {										
	Console::SetCursorPosition(x, y);						
	cout << "   | ~\_";										
	Console::SetCursorPosition(x, y + 1);
	cout << "[| _ | -";
	Console::SetCursorPosition(x, y + 2);
	cout << " (_)(_) ";
}

void Carro::mover() {
	Random r;
	dx = r.Next(1, 4);
	validarMovimiento(0, 0);
}