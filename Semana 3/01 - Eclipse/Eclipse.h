#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"

using namespace std;

class Eclipse
{
public:
	Eclipse();
	Eclipse(string ptipo, string psismos, string plluvias, string pvisibilidad, Fecha* pfecha, int phora);
	~Eclipse();
	void setTipo(string valor);
	void setSismos(string valor);
	void setLluvias(string valor);
	void setVisibilidad(string valor);
	void setFecha(Fecha* valor);
	void setHora(int valor);
	string getTipo       ();
	string getSismos     ();
	string getLluvias    ();
	string getVisibilidad();
	Fecha * getFecha      ();
	int getHora       ();
	void mostrarDatos();
private:
	string tipo, sismos, lluvias, visibilidad;
	Fecha* fecha;
	int hora;
};

Eclipse::Eclipse()
{
	tipo = "lunar";
	sismos = "si";
	lluvias = "si";
	visibilidad = "Asia";
	fecha = new Fecha(1, 1, 2000);
	hora = 100;
}

Eclipse::Eclipse(string ptipo, string psismos, string plluvias, string pvisibilidad, Fecha* pfecha, int phora) {
	tipo = ptipo;
	sismos = psismos;
	lluvias = plluvias;
	visibilidad = pvisibilidad;
	fecha = pfecha;
	hora = phora;
}

Eclipse::~Eclipse()
{
}

void Eclipse::setTipo(string valor) { tipo = valor; }
void Eclipse::setSismos(string valor) { sismos = valor; }
void Eclipse::setLluvias(string valor) { lluvias = valor; }
void Eclipse::setVisibilidad(string valor) { visibilidad = valor; }
void Eclipse::setFecha(Fecha* valor) { fecha = valor; }
void Eclipse::setHora(int valor) { hora = valor; }

string Eclipse::getTipo        (){return tipo;}
string Eclipse::getSismos      (){return sismos;}
string Eclipse::getLluvias     (){return lluvias;}
string Eclipse::getVisibilidad (){return visibilidad;}
Fecha * Eclipse::getFecha      (){return fecha;}
int Eclipse::getHora           (){return hora;}

void Eclipse::mostrarDatos() {
	cout << tipo << "\t" << sismos << "\t" << lluvias << "\t" << visibilidad << "\t" << fecha->getFecha() << "\t" << hora << "\n";
}