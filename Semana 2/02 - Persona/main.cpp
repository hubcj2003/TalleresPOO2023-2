#include "Persona.h"

void main() {
	string nombre;
	int edad;
	string DNI;
	char sexo;
	float peso;
	float altura;
	cout << "Ingrese nombre : ";
	cin >> nombre;
	cout << "Ingrese edad : ";
	cin >> edad;
	cout << "Ingrese DNI : ";
	cin >> DNI;
	cout << "Ingrese sexo : ";
	cin >> sexo;
	cout << "Ingrese peso : ";
	cin >> peso;
	cout << "Ingrese altura : ";
	cin >> altura;


	//PERSONA 1
	Persona* persona1 = new Persona(nombre, edad, DNI, sexo, peso, altura);
	cout << "Peso ideal : " << persona1->calcularIMC() << endl;
	cout << "Es mayor de edad? : " << persona1->esMayorDeEdad() << endl;
	cout << "Persona 1 : " << persona1->toString() << endl;

	//PERSONA 2
	Persona* persona2 = new Persona(nombre, edad, sexo);
	persona2->setPeso(40);
	persona2->setAltura(1.80);
	cout << "Peso ideal : " << persona2->calcularIMC() << endl;
	cout << "Es mayor de edad? : " << persona2->esMayorDeEdad() << endl;
	cout << "Persona 1 : " << persona2->toString() << endl;

	//PERSONA 3
	Persona* persona3 = new Persona();
	persona3->setNombre("Juan");
	persona3->setEdad(15);
	persona3->setSexo('H');
	persona3->setPeso(40);
	persona3->setAltura(1.80);
	cout << "Peso ideal : " << persona3->calcularIMC() << endl;
	cout << "Es mayor de edad? : " << persona3->esMayorDeEdad() << endl;
	cout << "Persona 1 : " << persona3->toString() << endl;


	system("pause");
}