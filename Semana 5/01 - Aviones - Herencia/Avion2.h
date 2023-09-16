#pragma once
#include "Avion.h"
class Avion2 : public Avion
{
public:
	Avion2();
	~Avion2();
	void dibujar();
private:

};

Avion2::Avion2() : Avion(19, 3)
{

}

Avion2::~Avion2()
{
}
void Avion2::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "________ | ________";
	Console::SetCursorPosition(x, y + 1);
	cout << "_ | _____0_____ | _";
	Console::SetCursorPosition(x, y + 2);
	cout << "        | |";
}