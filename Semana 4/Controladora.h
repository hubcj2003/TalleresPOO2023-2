#pragma once
#include <vector>
#include <conio.h>
#include "Monigote.h"
#include "Fantasma.h"
#include "Corazon.h"
class Controladora
{
public:
	Controladora();
	~Controladora();
	void mover();
	void dibujar();
	void borrar();
	void jugar();
private:
	vector<Corazon*> corazones;
	vector<Fantasma*> fantasmas;
	Monigote* monigote;
};

Controladora::Controladora()
{
	for (int i = 0; i < 12; i++)
		corazones.push_back(new Corazon());
	for (int i = 0; i < 3; i++)
		fantasmas.push_back(new Fantasma());
	monigote = new Monigote();
}

Controladora::~Controladora()
{
	delete monigote;
	for (int i = 0; i < corazones.size(); i++)
		delete corazones[i];
	for (int i = 0; i < fantasmas.size(); i++)
		delete fantasmas[i];
	corazones.clear();
	fantasmas.clear();
}

void Controladora::mover(){
	for (int i = 0; i < fantasmas.size(); i++)
		fantasmas[i]->mover();
	monigote->mover();
}
void Controladora::dibujar(){
	for each (Corazon * corazon in corazones) //[H, J, K, L, P]
		corazon->dibujar();
	for (int i = 0; i < fantasmas.size(); i++)
		fantasmas[i]->dibujar();
	monigote->dibujar();
}
void Controladora::borrar(){
	for (int i = 0; i < fantasmas.size(); i++)
		fantasmas[i]->borrar();
	monigote->borrar();
}
void Controladora::jugar(){
	char tecla = NULL;
	do
	{
		borrar();
		mover();
		dibujar();
		if (kbhit())
			tecla = toupper(getch());
		monigote->direccion(tecla);
		_sleep(50);
	} while (tecla != 'X');
}