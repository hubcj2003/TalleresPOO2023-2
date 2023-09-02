#pragma once
#include <iostream>
#include <string>

using namespace std;

class Plato
{
public:
	Plato(string pnombre, int ptemperatura, int pcantidadCalorias, float pprecio, string pesPicante);
	~Plato();
	string getInfo();
	void setnombre(string valor);
	void settemperatura(int valor);
	void setesPicante(string valor);
	int gettemperatura();
	float getprecio();
	string getesPicante();
private:
	string nombre;
	int temperatura;
	int cantCalorias;
	float precio;
	string esPicante;
};

Plato::Plato(string pnombre, int ptemperatura, int pcantidadCalorias, float pprecio, string pesPicante)
{
	nombre = pnombre;
	temperatura = ptemperatura;
	esPicante = pesPicante;
	precio = pprecio;
	cantCalorias = pcantidadCalorias;
}
Plato::~Plato()
{
}

string Plato::getInfo() {
	return nombre + "\t" + to_string(precio) + "\t" + to_string(temperatura) + "\t" + esPicante + "\t" + to_string(cantCalorias)+ "\n";
}

void  Plato::setnombre		 (string valor) {nombre		= valor;  }
void  Plato::settemperatura		 (int valor)    {temperatura		= valor;  }
void  Plato::setesPicante     (string valor) {esPicante     = valor; }

int    Plato::gettemperatura() { return temperatura; }
string Plato::getesPicante() { return esPicante; }
float Plato::getprecio() { return precio;  }