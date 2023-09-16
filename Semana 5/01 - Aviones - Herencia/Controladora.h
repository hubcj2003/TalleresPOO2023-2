#pragma once
#include "Avion1.h"
#include "Avion2.h"
#include "Avion3.h"
class Controladora
{
public:
	Controladora();
	~Controladora();
	void mover();
	void borrar();
	void dibujar();
	void jugar();
private:
	Avion1* avion1;
	Avion2* avion2;
	Avion3* avion3;
	char opcion;
};

Controladora::Controladora()
{
	avion1 = new Avion1();
	avion2 = new Avion2();
	avion3 = new Avion3();
}

Controladora::~Controladora()
{
	delete avion1;
	delete avion2;
	delete avion3;
}

void Controladora::mover(){
	switch (opcion)
	{
	case '1': avion1->mover(); break;
	case '2': avion2->mover(); break;
	case '3': avion3->mover(); break;
	}
}
void Controladora::borrar() {
	switch (opcion)
	{
	case '1': avion1->borrar(); break;
	case '2': avion2->borrar(); break;
	case '3': avion3->borrar(); break;
	}
}
void Controladora::dibujar() {
	switch (opcion)
	{
	case '1': avion1->dibujar(); break;
	case '2': avion2->dibujar(); break;
	case '3': avion3->dibujar(); break;
	}
}
void Controladora::jugar() {
	cout << "Ingrese el avion que desea usar (1 - 3) : ";
	opcion = getch();
	Console::Clear();
	do
	{
		borrar();
		mover();
		dibujar();
		_sleep(50);
	} while (true);
}