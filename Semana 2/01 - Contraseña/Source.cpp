#include "Contrasenia.h"
#include <vector>
#include <conio.h>

void main() {
	srand(time(0));
	vector<Contrasenia> contrasenias;
	vector<bool> siFuertes;
	int n = 5 + rand() % 6;
	for (int i = 0; i < n; i++) {
		Contrasenia contra = Contrasenia(5 + rand() % 15);
		contrasenias.push_back(contra);
		bool siFuerte = contra.esSeguro();
		siFuertes.push_back(siFuerte);
	}
	for (int i = 0; i < contrasenias.size(); i++)
		cout << contrasenias[i].getContrasenia() << " - " << siFuertes[i] << endl;
	getch();
}