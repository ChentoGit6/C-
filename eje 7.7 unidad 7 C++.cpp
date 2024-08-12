#include <iostream>
using namespace std;
//Ejercicio 7.7
//Escriba un programa que permita Ingresar tres números e informe el valor del mayor de ellos.
int main(int argc, char *argv[]) {
	float number1, number2, number3;
	cin >> number1 >> number2 >> number3;
	if (number1 > number2 && number1 > number3)
		cout << "El numero mayor es " << number1 << endl;
	else
		if (number2 > number1 && number2 > number3)
			cout << "El numero mayor es " << number2 << endl;
		else
			if (number3 > number2 && number3 > number1)
				cout << "El numero mayor es " << number3 << endl;
	return 0;
}

