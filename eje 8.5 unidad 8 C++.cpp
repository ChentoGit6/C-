#include <iostream>
using namespace std;
///Desarrolle una funci�n llamada Intercambia(...) que reciba dos variables enteras
///por referencia e intercambie sus valores. Escriba dos sobrecargas de la funci�n
///que permitan realizar el mismo procedimiento con dos datos de tipo real, y dos de
///tipo caracter. Pruebe las funciones desde un programa cliente.

void  intercambia(int &a, int &b);

int main(int argc, char *argv[]) {
	int a = 15;
	int b = 30;
	cout << a <<" "<< b << endl;
	intercambia (a, b);
	cout << a <<" "<< b << endl;
	return 0;
}

void  intercambia(int &a, int &b){
	int aux = b;
	b = a;
	a = aux;
}

