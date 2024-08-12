#include <iostream>
#include <matrix>
#include <vector>
using namespace std;
/*Escriba una función C++ que reciba una matriz de enteros. La función debe intercambiar
las filas de la matriz de modo que la fila de mayor suma de sus elementos quede primera (fila 0), y la fila
de 2da mayor suma en 2do lugar (fila 1).
*/

//void matrizenteros (matrix<int>m){
//	for(size_t i=0;i<m.size();i++) { 
//		
//	}
//}
int buscar (matrix<int>m, int f){
	int mayorindice=-1;
	int sumamayor = 0;
	for(size_t i=f;i<m.size(0);i++) {
		int suma = 0;
		for(size_t j=0;j<m.size(1);j++) { 
			suma += m[i][j];
		} 
		if (suma>sumamayor){
			sumamayor=suma;
			mayorindice=i;
		}
	}
	return mayorindice;
}
matrix <int> intercambia(matrix<int>m, int i, int j){
	vector<int>v;
	for(size_t k=0;k<m.size(1);k++) { 
		v.push_back(m[i][k]);
	}
	for(size_t k=0;k<m.size(1);k++) { 
		m[i][k]=m[j][k];
	}
	for(size_t k=0;k<m.size(1);k++) {
		m[j][k]=v[k];
	}
	return m;
}
matrix<int>problema(matrix<int>m){
	int i = buscar(m,0);
	m = intercambia(m,0,i);
	i = buscar(m,1);
	m = intercambia(m,1,i);
	return m;
}
	
int main() {
	cout<<"hola";
	matrix<int>m(3,3);
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			cin>>m[i][j];
		}
	}
	m = problema(m);
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			cout<<m[i][j]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}

