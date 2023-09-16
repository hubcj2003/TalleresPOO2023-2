#pragma once
#include "Nave.h"
class Gamma : public Nave
{
public:
	Gamma();
	~Gamma();
	void dibujar();
private:

};

Gamma::Gamma() : Nave(17, 10)
{
	tipo = 3;
	x = anchoConsola - 17;
}

Gamma::~Gamma()
{
}
void Gamma::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "        .		";
	Console::SetCursorPosition(x, y + 1);
	cout << "        |		";
	Console::SetCursorPosition(x, y + 2);
	cout << "   . - \"^\" - .	";
	Console::SetCursorPosition(x, y + 3);
	cout << "   / _....._\\	";
	Console::SetCursorPosition(x, y + 4);
	cout << "  . - \"` `\" - .";
	Console::SetCursorPosition(x, y + 5);
	cout << "  (ooo ooo ooo)	";
	Console::SetCursorPosition(x, y + 6);
	cout << "'-.,_________,.-'";
	Console::SetCursorPosition(x, y + 7);
	cout << "       / \\		";
	Console::SetCursorPosition(x, y + 8);
	cout << "     _ / \\_		";
	Console::SetCursorPosition(x, y + 9);
	cout << "     `\"` `\"`";


}