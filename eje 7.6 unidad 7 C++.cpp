#include <iostream>
#include <cmath>
using namespace std;
//Ejercicio 7.6
//Ingrese un número e informe: a) si es par o impar; b) si es múltiplo de 5 y 3 a la vez.
int main(int argc, char *argv[]) {
	//a)
	int numero;
	cin >> numero;
	if (numero % 2 == 0)
		cout << "Es par" << endl;
	else
		cout << "Es impar" << endl;
	
	//b)
	if (numero % 15 == 0)
		cout << "Es multiplo de 5 y 3 a la vez" << endl;
	else 
		cout << "No es multiplo de 5 y 3 a la vez" << endl;
	return 0;
}

