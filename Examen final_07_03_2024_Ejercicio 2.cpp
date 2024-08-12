#include <iostream>
#include <vector>
using namespace std;
//a) Diseñe una función que elimine elementos repetidos de un vector de enteros ordenado en forma creciente que se le pasa como parámetro.
//b) Escriba un programa C++ que permita ingresar números enteros por teclado y almacenarlos en un vector. El programa debe ir agregándolos 
//al vector en orden creciente (es decir, insertarlos donde corresponda para mantener el orden, no ordenarios después). 
//c) Luego el programa debe invocar la función creada en (a) y mostrar el vector resultante (ordenado y sin repetidos).

vector<int>eliminar_elementos (vector<int>&v){
	for(size_t i=0;i<v.size();i++) { 
		if(v[i-1]==v[i]){
			v[i]=0;
			v[i+1]=v[i];
		}
	}
	v.resize(v.size()-1);
	return v;
}
void mostrar (vector<int>v){
	for(size_t i=0;i<v.size();i++) { 
		cout << i <<"  ";
	}
}
int main() {
	vector<int>v(10);
	for(size_t i=0;i<v.size();i++) { 
		cin >> v[i];
	}
	eliminar_elementos(v);
	mostrar(v);
	return 0;
}

