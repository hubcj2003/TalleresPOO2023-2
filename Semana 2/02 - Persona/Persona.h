#pragma once
#include <iostream>
#include <string>
using namespace std;
class Persona
{
public:
	Persona();
	Persona(string pnombre, int pedad, char psexo);
	Persona(string pnombre, int pedad, string pDNI, char psexo, float ppeso, float paltura);
	~Persona();

	int calcularIMC();
	bool esMayorDeEdad();
	void comprobarSexo(char sexo);
	string toString();
	void generaDNI();

	string getNombre();
	int getEdad();
	char getSexo();
	float getPeso();
	float getAltura();
	void setNombre(string pnombre);
	void setEdad(int pedad);
	void setSexo(char psexo);
	void setPeso(float ppeso);
	void setAltura(float paltura);
private:
	string nombre;
	int edad;
	string DNI;
	char sexo;
	float peso;
	float altura;
};

Persona::Persona()
{
	 nombre = "";
	 edad = 0;
	 sexo = 'H';
	 peso = 0;
	 altura = 0;
	 generaDNI();
}

Persona::Persona(string pnombre, int pedad, char psexo)
{
	nombre = pnombre;
	edad = pedad;
	comprobarSexo(psexo);
	peso = 0;
	altura = 0;
	generaDNI();
}

Persona::Persona(string pnombre, int pedad, string pDNI, char psexo, float ppeso, float paltura)
{
	nombre = pnombre;
	edad = pedad;
	DNI = pDNI;
	comprobarSexo(psexo);
	peso = ppeso;
	altura = paltura;
}

Persona::~Persona()
{
}

int Persona::calcularIMC() {
	float imc = peso / pow(altura, 2);
	if (imc < 20) return -1;
	else if (imc <= 25) return 0;
	else return 1;
}

bool Persona::esMayorDeEdad() {
	if (edad >= 18) return true;
	else return false;
	//return edad >= 18;
}
void Persona::comprobarSexo(char sexo) {
	if (sexo == 'H' || sexo == 'M')
		this->sexo = sexo;
	else
		this->sexo = 'H';
}
string Persona::toString() {
	return nombre + "\t" + to_string(edad) + "\t" + DNI + "\t" + sexo + "\t" + to_string(peso) + "\t" + to_string(altura) + "\n";
}
void Persona::generaDNI() {
	DNI = "";
	for (int i = 0; i < 8; i++)
		DNI += to_string(rand() % 10);
}

string Persona::getNombre()
{
	return nombre;
}

int Persona::getEdad()
{
	return edad;
}


char Persona::getSexo()
{
	return sexo;
}

float Persona::getPeso()
{
	return peso;
}

float Persona::getAltura()
{
	return altura;
}

void Persona::setNombre(string pnombre)
{
	nombre = pnombre;
}

void Persona::setEdad(int pedad)
{
	edad = pedad;
}

void Persona::setSexo(char psexo)
{
	sexo = psexo;
}

void Persona::setPeso(float ppeso)
{
	peso = ppeso;
}

void Persona::setAltura(float paltura)
{
	altura = paltura;
}
