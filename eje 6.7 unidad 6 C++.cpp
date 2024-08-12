#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	string nombre;
    int fecha;
	int dia;
	int mes;
	int anio;
	
	cout << "Ingrese el nombre: ";
	cin >> nombre;
	cout << "Ingrese la fecha de nacimiento (en formato aaaammdd): ";
	cin >> fecha;
	
	dia = fecha % 100;
	mes = (fecha % 10000)/100;
	anio = fecha / 10000;
	
	cout << nombre << ": " << dia << "/" << mes << "/" << anio;
	return 0;
}

