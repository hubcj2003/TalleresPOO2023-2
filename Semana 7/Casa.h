#pragma once
#include "Figura.h"
class Casa : public Figura
{
public:
	Casa();
	~Casa();
	void dibujar();
private:

};

Casa::Casa()
{
	alto = 5;
	ancho = 7;
	x = anchoConsola - ancho;
	y = altoConsola - alto;
	dx = dy = 0;
}

Casa::~Casa()
{
}

void Casa::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "  +";
	Console::SetCursorPosition(x, y +1);
    cout << "  A_";
	Console::SetCursorPosition(x, y +2);
    cout << " /\\-\\";
	Console::SetCursorPosition(x, y +3);
	cout << "_||\"|_";
	Console::SetCursorPosition(x, y +4);
    cout << "^~^~^~^";
}