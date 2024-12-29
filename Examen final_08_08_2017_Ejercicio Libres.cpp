/*Libres 15pts) Escriba una función inserta_col que reciba una matriz A de NxM float, 
un vector V de N float, y un entero i entre 0 y M-1. La función debe modificar la matriz A, 
insertando una nueva columna iésima colocando en ella los valores del vector V
*/

#include <iostream>
#include <matrix>
using namespace std;

void inserta_col (matrix<float>&A, vector<float>V, int i){
	A.resize(A.size(0),A.size(1)+1);
	int cont = 0;
	for(size_t j=A.size(1)-1;j>i;j--) { 
		A[cont][j] = A[cont][j-1];
	}
	for(size_t k=0;k<A.size(0);k++) { 
		A[k][i-1] = V[k];
	}
}

int main() {
	cout << "Ingrese el tamaño de la matriz:" << endl;
	int f,c;
	cout << "  -Filas: "; cin >> f;
	cout << "  -Columnas: "; cin >> c;
	matrix<float>A(f,c,0);
	vector<float>V(f,1);
	int i;
	cout << "Ingrese número entre 0 y " << c-1 << ": "; cin >> i;
	inserta_col (A,V,i);
	for(size_t i=0;i<A.size(0);i++) { 
		for(size_t j=0;j<A.size(1);j++) { 
			cout << A[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}

