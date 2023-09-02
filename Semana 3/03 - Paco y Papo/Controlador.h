#pragma once
#include "Contacto.h"
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
	void mostrarVarones();
	void mostrarFacebookWhatsapp();
	void cumpleSeptiembre();
private:
	vector<Contacto*> contactos;
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
		cout << "4 - Varones\n";
		cout << "5 - Facebook WhatsApp\n";
		cout << "6 - Cumpleaños en septiembre\n";
		cout << "7 - Mostrar datos\n";
		cout << "0 - Salir\n";
		cout << "Ingrese la opcion : ";
		cin >> op;
		switch (op)
		{
		case 1: registrarDatos(); break;
		case 2: modificarDatos(); break;
		case 3: eliminarDatos(); break;
		case 4: mostrarVarones(); break;
		case 5: mostrarFacebookWhatsapp(); break;
		case 6: cumpleSeptiembre(); break;
		case 7:  mostrarDatos(); break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}

void Controlador::registrarDatos() {
	string nombre,  sexo, facultad, redSocial,  email;
	int telefono, dia, mes, anio;
	Fecha* fecha;
	cout << "Ingrese el nombre : ";
	cin >> nombre;
	cout << "Ingrese sexo: ";
	cin >> sexo;
	cout << "Ingrese facultad: ";
	cin >> facultad;
	cout << "Ingrese redSocial : ";
	cin >> redSocial;
	cout << "Ingrese email : ";
	cin >> email;
	cout << "Ingrese telefono : ";
	cin >> telefono;
	cout << "Ingrese la fecha (dd mm aaaa) : ";
	cin >> dia >> mes >> anio;
	Contacto* contacto = new Contacto(nombre, telefono, sexo, facultad, redSocial, fecha, email);
	contactos.push_back(contacto);
}

void Controlador::modificarDatos() {
	int indice;
	string nombre, sexo, facultad, redSocial, email;
	int telefono, dia, mes, anio;
	Fecha* fecha;
	mostrarDatos();
	cout << "Ingrese dato a modificar : ";
	cin >> indice;
	cout << "Ingrese el nombre : ";
	cin >> nombre;
	//cout << "Ingrese sexo: ";
	//cin >> sexo;
	//cout << "Ingrese facultad: ";
	//cin >> facultad;
	//cout << "Ingrese redSocial : ";
	//cin >> redSocial;
	//cout << "Ingrese email : ";
	//cin >> email;
	//cout << "Ingrese telefono : ";
	//cin >> telefono;
	//cout << "Ingrese la fecha (dd mm aaaa) : ";
	//cin >> dia >> mes >> anio;
	contactos[indice]->setnombre(nombre);
}
void Controlador::eliminarDatos() {
	int indice;
	mostrarDatos();
	do
	{
		cout << "Ingrese dato a eliminar : "; //3
		cin >> indice; //[][][][]
	} while (!(indice >= 0 && indice < contactos.size()));
	contactos.erase(contactos.begin() + indice);
}
void Controlador::mostrarDatos() {
	for (int i = 0; i < contactos.size(); i++)
		cout << i <<  " - " << contactos[i]->getInfo();
}

void Controlador::mostrarVarones() {
	for (int i = 0; i < contactos.size(); i++)
		if(contactos[i]->getsexo() == "varon")
			cout << i << " - " << contactos[i]->getInfo();
}
void Controlador::mostrarFacebookWhatsapp() {
	for (int i = 0; i < contactos.size(); i++)
		if (contactos[i]->getredSocial() == "Facebook" || contactos[i]->getredSocial() == "WhatsApp")
			cout << i << " - " << contactos[i]->getInfo();
}
void Controlador::cumpleSeptiembre() {
	for (int i = 0; i < contactos.size(); i++)
		if (contactos[i]->getFecha()->getMes() == 9)
			cout << i << " - " << contactos[i]->getInfo();
}
