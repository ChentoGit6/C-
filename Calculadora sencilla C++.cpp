#include <iostream>
using namespace std;

int main() {
	
	char op;
	float num1;
	float num2;
	float resultado;
	
	cout << "########## CALCULADORA ##########" << endl;
	
	cout << "Ingrese (+ - * /): ";
    cin >> op;
	cout << "Ingrese el Número 1: ";
	cin >> num1;
	cout << "Ingrese el Número 2: ";
	cin >> num2;
	
	switch (op){
		case '+':
		resultado = num1 + num2;
		cout << "El resultado es: " << resultado << endl;
		break;
		case '-':
		resultado = num1 - num2;
		cout << "El resultado es: " << resultado << endl;
		break;
		case '*':
		resultado = num1 * num2;
		cout << "El resultado es: " << resultado << endl;
		break;
		case '/':
		resultado = num1 / num2;
		cout << "El resultado es: " << resultado << endl;
		break;
	}
	cout << "#################################";
	return 0;
}

