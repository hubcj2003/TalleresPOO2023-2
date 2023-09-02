#pragma once
#include "Plato.h"
#include <vector>

class Controlador
{
public:
	Controlador();
	~Controlador();
	void menu();
	void registrarDatos();
	void modificarDatos();
	void eliminarDatos();
	void mostrarDatos();
	void platosPicante();
	void platosCaros();
private:
	vector<Plato*> platos;
};

Controlador::Controlador()
{

}

Controlador::~Controlador()
{
}

void Controlador::menu() {
	int op;
	do
	{
		cout << "1 - Registrar datos\n";
		cout << "2 - Modificar datos\n";
		cout << "3 - Eliminar datos\n";
		cout << "4 - Platos picantes\n";
		cout << "5 - Platos caros\n";
		cout << "6 - Mostrar datos\n";
		cout << "0 - Salir\n";
		cout << "Ingrese la opcion : ";
		cin >> op;
		switch (op)
		{
		case 1: registrarDatos(); break;
		case 2: modificarDatos(); break;
		case 3: eliminarDatos(); break;
		case 4: platosPicante(); break;
		case 5: platosCaros(); break;
		case 6:  mostrarDatos(); break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}

void Controlador::registrarDatos() {
	string nombre, esPicante;
	int temperatura, cantCalorias;
	float precio;
	cout << "Ingrese el nombre : ";
	cin >> nombre;
	cout << "Ingrese si es picante (si no): ";
	cin >> esPicante;
	cout << "Ingrese temperatura: ";
	cin >> temperatura;
	cout << "Ingrese cantidad de calorias : ";
	cin >> cantCalorias;
	cout << "Ingrese el precio : ";
	cin >> precio;
	Plato* plato = new Plato(nombre, temperatura, cantCalorias, precio, esPicante);
	platos.push_back(plato);
}

void Controlador::modificarDatos() {
	int indice;
	string nombre, esPicante;
	int temperatura, cantCalorias;
	float precio;
	mostrarDatos();
	cout << "Ingrese dato a modificar : ";
	cin >> indice;
	cout << "Ingrese el nombre : ";
	cin >> nombre;
	//cout << "Ingrese si es picante (si no): ";
	//cin >> esPicante;
	//cout << "Ingrese temperatura: ";
	//cin >> temperatura;
	//cout << "Ingrese cantidad de calorias : ";
	//cin >> cantCalorias;
	//cout << "Ingrese el precio : ";
	//cin >> precio;
	platos[indice]->setnombre(nombre);
}
void Controlador::eliminarDatos() {
	int indice;
	mostrarDatos();
	cout << "Ingrese dato a eliminar : "; //3
	cin >> indice; //[][][][]
	platos.erase(platos.begin() + indice);
}
void Controlador::mostrarDatos() {
	for (int i = 0; i < platos.size(); i++)
		cout << i <<  " - " << platos[i]->getInfo();
}

void Controlador::platosPicante() {
	for (int i = 0; i < platos.size(); i++)
		if(platos[i]->getesPicante() == "si")
			cout << i << " - " << platos[i]->getInfo();
}
void Controlador::platosCaros() {
	for (int i = 0; i < platos.size(); i++)
		if (platos[i]->getprecio() > 100)
			cout << i << " - " << platos[i]->getInfo();
}