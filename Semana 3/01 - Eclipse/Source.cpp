#include "Eclipse.h"
#include <vector>

void mostrar(vector<Eclipse*> eclipses) {
	cout << "ECLIPSES : \n";
	cout << "tipo\tsismos\tlluvias\tvisibilidad\tfecha\thora\n";
	for (int i = 0; i < eclipses.size(); i++) {
		cout << i << " ";
		eclipses[i]->mostrarDatos();
	}
}

void main() {
	int op;
	string tipo, sismos, lluvias, visibilidad;
	int dia, mes, anio, hora, pos;
	vector<Eclipse*> eclipses;
	do
	{
		do
		{
			cout << "1 - Registrar datos\n";
			cout << "2 - Modificar datos\n";
			cout << "3 - Eliminar datos\n";
			cout << "4 - Reporte de eclipses que se produjeron en la noche.\n";
			cout << "5 - Reporte de eclipses que fueron visibles en Europa.\n";
			cout << "6 - Reporte de eclipses que ocasionaron sismos.\n";
			cout << "7 - Mostrar datos.\n";
			cout << "0 - Salir\n";
			cout << "Ingrese la opcion : ";
			cin >> op;
		} while (!(op >=0 && op <= 7));
		switch (op)
		{
		case 1:

			cout << "Ingrese tipo de eclipse (solar - lunar) : ";
			cin >> tipo;
			cout << "Ingrese fecha (dd mm aaaa) : ";
			cin >> dia>> mes>> anio;
			cout << "Ingrese hora (100 - 2300) : ";
			cin >> hora;
			cout << "Ingrese sismos (si - no) : ";
			cin >> sismos;
			cout << "Ingrese lluvias (si - no) : ";
			cin >> lluvias;
			cout << "Ingrese visibilidad (America del Sur,Europa, África, America del Norte, Asia) : ";
			cin >> visibilidad;
			eclipses.push_back(new Eclipse(tipo, sismos, lluvias, visibilidad, new Fecha(dia, mes, anio), hora));
			break;
		case 2: 
			mostrar(eclipses);
			cout << "Ingrese la posicion del eclipse que desea modificar : ";
			cin >> pos;
			cout << "Ingrese tipo de eclipse (solar - lunar) : ";
			cin >> tipo;
			cout << "Ingrese fecha (dd mm aaaa) : ";
			cin >> dia >> mes >> anio;
			cout << "Ingrese hora (100 - 2300) : ";
			cin >> hora;
			cout << "Ingrese sismos (si - no) : ";
			cin >> sismos;
			cout << "Ingrese lluvias (si - no) : ";
			cin >> lluvias;
			cout << "Ingrese visibilidad (America del Sur,Europa, África, America del Norte, Asia) : ";
			cin >> visibilidad;
			eclipses[pos]->setTipo(tipo);
			eclipses[pos]->setFecha(new Fecha(dia, mes, anio));
			eclipses[pos]->setHora(hora);
			eclipses[pos]->setSismos(sismos);
			eclipses[pos]->setLluvias(lluvias);
			eclipses[pos]->setVisibilidad(visibilidad);
			break;
		case 3:
			mostrar(eclipses);
			cout << "Ingrese la posicion del eclipse que desea eliminar : ";
			cin >> pos;
			eclipses.erase(eclipses.begin() + pos);
			break;
		case 4:
			for (int i = 0; i < eclipses.size(); i++)
				if (eclipses[i]->getHora() > 1800)
					eclipses[i]->mostrarDatos();

			break;
		case 5:
			for (int i = 0; i < eclipses.size(); i++)
				if (eclipses[i]->getVisibilidad() == "Europa")
					eclipses[i]->mostrarDatos();

			break;
		case 6: 
			for (int i = 0; i < eclipses.size(); i++)
				if (eclipses[i]->getSismos() == "si")
					eclipses[i]->mostrarDatos();
			break;
		case 7:
			mostrar(eclipses);
			break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}