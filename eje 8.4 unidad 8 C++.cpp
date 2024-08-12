#include <iostream>
using namespace std;
/*Escriba una función que determine el mayor de 3 valores enteros positivos.
Modifique la función para que, utilizando parámetros por defecto, sirva también
para determinar el mayor de 2 parámetros.
*/
int funcion (int num1,int num2,int num3){
	int mayor;
	if (num1>num2 && num1>num3){
		mayor = num1;
	}else {
		if (num2>num1 && num2>num3){
			mayor = num2;
		}else{
			if (num3>num2 && num3>num1){
			mayor = num3;}
		}
	}
	return mayor;
}
int main() {
	cout << "Ingrese 3 numero enteros positivos :"<<endl;
	int num1, num2, num3;
	cin >> num1;
	cin >> num2;
	cin >> num3;
	
	int mayor = funcion (num1, num2, num3);
	cout << "El mayor es: "<<mayor<<endl;
	return 0;
}

