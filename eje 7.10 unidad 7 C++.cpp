#include <iostream>
using namespace std;
//Ejercicio 7.10
//Escriba un programa C++ que permita ingresar natural N como dato. Obtener todos los pares menores a N. 
//Tener en cuenta que el dato puede ser tanto par
//como impar. Debe dar al usuario la posibilidad de seleccionar por un menú la opción de visualizar el listado:
//a) En forma creciente.
//b) En forma decreciente.
int main(int argc, char *argv[]) {
	int N;
	
	cin >> N;
	
	char letra;
	cout << "Ingrese la forma en la que quiera ver el listado, creciente o decreciente, ingrese c/d" << endl;
	cin >> letra;
	
	if (letra == 'c')
		for (int i=0; i<=N; i += 1){
			if (i % 2 == 0)
				cout << " Es par " << i << endl;
	}
	if (letra == 'd')
		for (int i=N; i>=0; i -= 1){
			if (i % 2 == 0)
				cout << " Es par " << i << endl;
		}
	return 0;
}

