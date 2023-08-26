#pragma once
#include <iostream>
#include <string>

using namespace std;

class Contrasenia
{
public:
	Contrasenia();
	Contrasenia(int plongitud);
	~Contrasenia();
	bool esSeguro();
	void generarContrasenia();
	string getContrasenia();
private:
	int longitud;
	string contrasenia;
};

Contrasenia::Contrasenia()
{
	longitud = 15;
	contrasenia = "";
	generarContrasenia();
}

Contrasenia::Contrasenia(int plongitud)
{
	longitud = plongitud;
	contrasenia = "";
	generarContrasenia();
}

Contrasenia::~Contrasenia()
{
}

bool Contrasenia::esSeguro() {
	int cMayuscula = 0, cMinuscula = 0, cNumeros = 0;
	for (int i = 0; i < contrasenia.size(); i++)
		if (contrasenia[i] >= '0' && contrasenia[i] <= '9')
			cNumeros++;
		else if (contrasenia[i] >= 'a' && contrasenia[i] <= 'z')
			cMinuscula++;
		else if (contrasenia[i] >= 'A' && contrasenia[i] <= 'Z')
			cMayuscula++;
	return cNumeros > 5 && cMayuscula > 2 && cMinuscula > 1;
}

void Contrasenia::generarContrasenia() { 
	for (int i = 0; i < longitud; i++)
		switch (rand() % 3) // 0 1 2
		{
		case 0: contrasenia += 65 + rand() % (90 - 65 + 1); break;
		case 1: contrasenia += 97 + rand() % (122 - 97 + 1); break;
		case 2: contrasenia += to_string(rand() % 10); break;
		}
}

string Contrasenia::getContrasenia() {
	return contrasenia;
}