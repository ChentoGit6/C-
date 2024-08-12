#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	do{
		cout << "A. Ingresar un nuevo dato" << endl;
		cout << "B. Calcular el doble del dato" << endl;
		cout << "C. Determinar si es par" << endl;
		cout << "D. Determinar si es primo" << endl;
		cout << "E. Salir" << endl;
		cout << "Elegr opcion (A..E): " << endl;
		cin >> opcion_elegida;
		
		
	} while(opcion_elegida != 'E');
	return 0;
}

