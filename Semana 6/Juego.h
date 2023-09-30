#pragma once
#include "Bicicleta.h"
#include "Carro.h"
#include "Bus.h"
#include "Persona.h"
#include <vector>
#include <conio.h>
class Juego
{
public:
	Juego();
	~Juego();
	void gestionarTodo();
	bool colision();
	void jugar();
	void agregarTransporte();
	void borrar();
private:
	vector <Terrestre*> transportes;
	Persona* persona;
};

Juego::Juego()
{
	transportes.push_back(new Bicicleta());
	persona = new Persona();
}

Juego::~Juego()
{
}

void Juego::gestionarTodo() {
	for (int i = 0; i < transportes.size(); i++) {
		transportes[i]->borrar();
		transportes[i]->mover();
		transportes[i]->dibujar();
	}
	persona->borrar();
	persona->mover();
	persona->dibujar();
}
bool Juego::colision() {
	for (int i = 0; i < transportes.size(); i++)
		if (transportes[i]->getTipo() != 'I')
			if (transportes[i]->colision(persona->getX(), persona->getY(), persona->getAncho(), persona->getAlto()))
				return true;
	return false;
}

void  Juego::borrar() {
	for (int i = 0; i < transportes.size(); i++)
		if (transportes[i]->getDX() == 0) {
			transportes[i]->borrar();
			transportes.erase(transportes.begin() + i);
			i--;
		}
}
void Juego::jugar() {
	do
	{
		if (kbhit())
			persona->direccion(getch());
		gestionarTodo();
		agregarTransporte();
		borrar();
		//persona->direccion(NULL);
		_sleep(50);
	} while (!colision());
}
void Juego::agregarTransporte() {
	Random r;
	switch (r.Next(50))
	{
	case 1: case 2: transportes.push_back(new Carro()); break;
	case 3: case 4: transportes.push_back(new Bus()); break;
	case 5:
		if(r.Next(10) == 1)
			transportes.push_back(new Bicicleta());
		break;
	}
}