#include <iostream>
#include <vector>
using namespace std;
//a) Dise�e una funci�n que elimine elementos repetidos de un vector de enteros ordenado en forma creciente que se le pasa como par�metro.
//b) Escriba un programa C++ que permita ingresar n�meros enteros por teclado y almacenarlos en un vector. El programa debe ir agreg�ndolos 
//al vector en orden creciente (es decir, insertarlos donde corresponda para mantener el orden, no ordenarios despu�s). 
//c) Luego el programa debe invocar la funci�n creada en (a) y mostrar el vector resultante (ordenado y sin repetidos).

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

