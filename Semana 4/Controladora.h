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
	void colisionCorazones();
	bool colisionFantasmas();
private:
	int cantCorazon;
	vector<Corazon*> corazones;
	vector<Fantasma*> fantasmas;
	Monigote* monigote;
};

Controladora::Controladora()
{
	cantCorazon = 0;
	for (int i = 0; i < 10; i++)
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
		Console::SetCursorPosition(2, 2);
		cout << "CORAZONES: " << cantCorazon;
		if (corazones.size() == 0)
			break;
		borrar();
		mover();
		dibujar();
		if (kbhit())
			tecla = toupper(getch());
		monigote->direccion(tecla);
		colisionCorazones();
		_sleep(50);
	} while (!colisionFantasmas());
	Console::Clear();
	if (corazones.size() == 0)
		cout << "GANASTE";
	else
		cout << "PERDISTE";
	getch();
}

void Controladora::colisionCorazones() {
	for (int i = 0; i < corazones.size(); i++)
		if (monigote->colision(corazones[i]->getx(), corazones[i]->gety(),
			corazones[i]->getancho(), corazones[i]->getalto())) {
			cantCorazon++;
			corazones[i]->borrar();
			corazones.erase(corazones.begin() + i); //[G; H; K]
			i--;
		}
}

bool Controladora::colisionFantasmas() {
	for each (Fantasma * fantasma in fantasmas)
		if (monigote->colision(fantasma->getx(), fantasma->gety(),
			fantasma->getancho(), fantasma->getalto()))
			return true;
	return false;
}