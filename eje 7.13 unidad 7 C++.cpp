#include <iostream>
using namespace std;
//Ejercicio 7.13
//Una Empresa paga a sus 25 operarios semanalmente de acuerdo con la cantidad de horas trabajadas, a razón de X pesos la hora hasta 40 hs. y un 50%
//más por todas las horas que pasan de 40. Escriba un programa que permita ingresar el costo 
//inicial por hora (X), y luego la cantidad de horas trabajadas por cada empleado e informe el salario que le corresponde cobrar. Finalmente, debe
//informar a modo de resumen: a) los salarios máximo, mínimo y promedio, y b) el monto total que la empresa pagó en concepto de salarios.
int main(int argc, char *argv[]) {
	
	float X;
	cout << "ingresar el costo inicial por hora "<<endl;
	cin >> X;
	
	int matriz [1][4];
	
	for (int horas=0; horas<1; horas++) {
		for (int operario=1; operario<4; operario++) {
			cout << "Ingrese la cantidad de horas trabajadas por el operario "<<operario<<endl;
			cin >> matriz [horas][operario];
		}
	}
	cout<<endl;
	for (int horas=0; horas<1; horas++) {
		for (int operario=1; operario<4; operario++) {
			cout << "el operario "<<operario<<" trabajó "<< matriz [horas][operario]<<" horas,";
			if (matriz [horas][operario] <= 40){
				matriz [1][4] = matriz [horas][operario] * X;
				cout<<" le corresponde cobrar "<< matriz [1][4] ; }
			else
				if (matriz [horas][operario] > 40){
					matriz [1][4] = matriz [horas][operario] * X * 1.5;
					cout<<" le corresponde cobrar "<< matriz [1][4]<<" por concepto de 50%";}
			cout<<endl;
		}
	}
	return 0;
}

