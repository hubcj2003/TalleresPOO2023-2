#pragma once
#include "Nave.h"
class Beta : public Nave
{
public:
	Beta();
	~Beta();
	void dibujar();
private:

};

Beta::Beta() : Nave(11, 3)
{
	tipo = 2;
	x = (anchoConsola - 11) / 2;
}

Beta::~Beta()
{
}
void Beta::dibujar() {
	Console::SetCursorPosition(x, y);
	cout <<"   .-- - . ";
	Console::SetCursorPosition(x, y + 1);
	cout <<"_ / __~0_\_";
	Console::SetCursorPosition(x, y + 2);
	cout <<"(_________)";
}