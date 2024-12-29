/*Ejercicio 3 a) Defina un struct Licencia para representar una licencia de un software. El struct debe tener
campos para guardar el nombre del software (ejemplo: “ZinjaI”), el nombre de licencia (ejemplo “GPL”) y el
costo de la misma en dólares (ej: 0). b) Implemente una función calcular_costos que reciba dos vectores, uno con
una lista de licencias, y otro de igual tamaño con una lista de enteros, que indican las cantidades de cada una de
las licencias que necesita adquirir cierta institución. La función debe calcular y retornar el costo total de la
compra de todas esas licencias. c) Implemente un programa cliente que permita cargar los datos de N programas
(por cada uno, su licencia y la cantidad a comprar) y calcule y muestre el costo total.
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct licencia {
	string nombre;
	string licen;
	float costo;
};

float calcular_costo (vector<licencia>v, vector<int>f){
	float suma = 0;
	for(size_t i=0;i<v.size();i++) { 
		suma += (v[i].costo * f[i]);
	}
	return suma;
}
	

int main() {
	int N;
	cout << "Indique la cantidad de programas: "; cin >> N;
	vector<licencia>v(N);
	vector<int>f(N);
	cout << "Indique los datos de los mismos:" << endl;
	licencia a;
	int cant;
	for(size_t i=0;i<v.size();i++) { 
		cout << "  -Nombre: "; cin >> a.nombre;
		cout << "  -Licencia: "; cin >> a.licen;
		cout << "  -Costo: "; cin >> a.costo;
		cout << "  -Cantidad a comprar: "; cin >> cant;
		v[i] = a;
		f[i] = cant;
	}
	float total = calcular_costo (v,f);
	cout << fixed << setprecision(2);
	cout << "El costo total de las licencias es: usd$" << total;
	return 0;
}

