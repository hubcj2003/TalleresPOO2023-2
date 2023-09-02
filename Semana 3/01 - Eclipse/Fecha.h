#pragma once
#include <iostream>
#include <string>

using namespace std;
class Fecha
{
public:
	Fecha(); 
	Fecha(int pdia, int pmes, int panio);
	~Fecha();
	string getFecha();
private:
	int dia, mes, anio;
};

Fecha::Fecha()
{
}

Fecha::Fecha(int pdia, int pmes, int panio) {
	dia = pdia;
	mes = pmes;
	anio = panio;
}

Fecha::~Fecha()
{
}

string Fecha::getFecha() {
	return to_string(dia) + " - " + to_string(mes) + " - " + to_string(anio);
}