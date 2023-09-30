#pragma once
#define izquierda 75
#define derecha 77
#define arriba 72
#define abajo 80
#include "Figura.h"
class Monigote : public Figura
{
public:
	Monigote();
	~Monigote();
	void dibujar();
	void mover();
	void desplazamiento(char tecla);
	void reposicionar();
	bool getInmune();
	void hacerInmune();
	void quitarVidas();
	int getVidas();
	int getPasos();
private:
	int cantMovimientos;
	int cantPasos;
	bool inmune;
	int vidas;
};

Monigote::Monigote()
{
	cantPasos = 0;
	vidas = 3;
	alto = 2;
	ancho = 1;
	x = 0;
	y = 0;
	dx = dy = 0;
	inmune = false;
	cantMovimientos = 0;
}

Monigote::~Monigote()
{
}

void Monigote::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "O";
	Console::SetCursorPosition(x, y + 1);
	cout << "+";
}

void Monigote::mover() {
	movimiento(0, 0);
}

void Monigote::desplazamiento(char tecla) {
	dx = dy = 0;
	if (izquierda == tecla || tecla == derecha || tecla == abajo || tecla == arriba) {
		if (inmune) cantMovimientos++;
		if (cantMovimientos > 10) {
			inmune = false;
			cantMovimientos = 0;
		}
		cantPasos++;
		switch (tecla)
		{
		case izquierda: dx = -2; break;
		case derecha: dx = 2; break;
		case arriba: dy = -1; break;
		case abajo: dy = 1; break;
		}
	}
}

void Monigote::reposicionar() {
	x = y = 0;
}

bool Monigote::getInmune() { return inmune; }
void Monigote::hacerInmune() { inmune = true; }
void Monigote::quitarVidas() { vidas--; }
int Monigote::getVidas() { return vidas; }
int Monigote::getPasos() { return cantPasos; }