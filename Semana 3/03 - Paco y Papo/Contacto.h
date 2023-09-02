#pragma once
#include <iostream>
#include "Fecha.h"
#include <string>

using namespace std;

class Contacto
{
public:
	Contacto(string pnombre, int ptelefono, string psexo, string pfacultad, string predSocial, Fecha* fecha, string pemail);
	~Contacto();
	string getInfo();
	void setnombre(string valor);
	void settelefono(int valor);
	void setemail(string valor);
	int gettelefono();
	string getemail();
	string getsexo();
	string getredSocial();
	Fecha* getFecha();
private:
	string nombre;
	int telefono;
	string sexo, facultad, redSocial;
	Fecha* fecha;
	string email;
};

Contacto::Contacto(string pnombre, int ptelefono, string psexo, string pfacultad, string predSocial, Fecha * pfecha, string pemail)
{
	nombre = pnombre;
	telefono = ptelefono;
	sexo = psexo;
	facultad = pfacultad;
	redSocial = predSocial;
	fecha = pfecha;
	email = pemail;
}
Contacto::~Contacto()
{
}

string Contacto::getInfo() {
	return nombre + "\t" + to_string(telefono) + "\t" + sexo + "\t" + email + "\t" + facultad+ "\t" + redSocial + "\t" + fecha->getFecha() + "\n";
}

void  Contacto::setnombre		 (string valor) {nombre		= valor;  }
void  Contacto::settelefono		 (int valor)    {telefono		= valor;  }
void  Contacto::setemail     (string valor) {email     = valor; }

int    Contacto::gettelefono() { return telefono; }
string Contacto::getemail() { return email; }


string Contacto::getsexo() { return sexo; }
string Contacto::getredSocial() { return redSocial; }
Fecha* Contacto::getFecha() { return fecha;  }