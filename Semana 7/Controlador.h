#pragma once
#include "Virus.h"
#include "Vacuna.h"
#include "Monigote.h"
#include "Casa.h"
#include <conio.h>
#include <vector>

class Controlador
{
public:
	Controlador();
	~Controlador();
	void gestionarTodo();
	bool colision();
	void jugar();
private:
	vector<Figura *> figuras;
	Casa* casa;
	Monigote* monigote;
	int n;
	int cantidadVacunas;
	time_t tiempoInicial;
};

Controlador::Controlador()
{
	cantidadVacunas = 1;
	tiempoInicial = time(0);
	Random r;
	n = r.Next(3, 7);
	for (int i = 0; i < 0; i++)
		figuras.push_back(new Virus());
	figuras.push_back(new Vacuna());
	casa = new Casa();
	monigote = new Monigote();
}

Controlador::~Controlador()
{
}

void Controlador::gestionarTodo() {
	for (int i = 0; i < figuras.size(); i++) {
		figuras[i]->borrar();
		figuras[i]->mover();
		figuras[i]->dibujar();
	}
	casa->dibujar();
	monigote->borrar();
	monigote->mover();
	monigote->dibujar();
}
bool Controlador::colision() {
	for (int i = 0; i < figuras.size(); i++) {
		if (figuras[i]->colision(monigote->getX(), monigote->getY(), monigote->getAncho(), monigote->getAlto())) {
			if (monigote->getInmune() == false) {
				if (figuras[i]->getTipo() == "virus") {
					monigote->borrar();
					monigote->reposicionar();
					monigote->quitarVidas();
				}
				else
					monigote->hacerInmune();
				figuras[i]->borrar();
				figuras.erase(figuras.begin() + i);
				i--;
			}
		}
	}
	if (casa->colision(monigote->getX(), monigote->getY(), monigote->getAncho(), monigote->getAlto()))
		return true;
	if (monigote->getVidas() == 0)
		return true;
	return false;
}
void Controlador::jugar() {
	char tecla;
	do
	{
		tecla = NULL;
		Console::SetCursorPosition(anchoConsola, 1);
		cout << "Vidas: " << monigote->getVidas(); 
		Console::SetCursorPosition(anchoConsola, 2);
		cout << "Inmunidad: " << monigote->getInmune(); 
		Console::SetCursorPosition(anchoConsola, 3);
		cout << "Pasos: " << monigote->getPasos(); 
		if (kbhit())
			tecla = getch();
		monigote->desplazamiento(tecla);
		gestionarTodo();
		if (difftime(time(0), tiempoInicial) > 10 && cantidadVacunas < 5) {
			figuras.push_back(new Vacuna());
			tiempoInicial = time(0);
			cantidadVacunas++;
		}
		_sleep(50);
	} while (!colision());
	cout << "Cantidad de pasos del monigote: " << monigote->getPasos() << endl;
	getch();
	getch();
	getch();
}