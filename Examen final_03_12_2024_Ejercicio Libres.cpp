/*Ej Libres (20 pts) a) Escriba una función que reciba una matriz M de enteros y un valor entero x
y cuente cuántas veces aparece el valor x en la matriz b) Escriba una función para encontrar los dos
valores que más veces se repiten en una matriz de enteros. c) En un programa cliente, cargue una matriz de 
N×N elementos enteros con valores al azar entre 1 y 50, y utilice las funciones para encontrar e informar 
cuáles son los dos valores que más veces se repiten y cuántas veces se repite cada uno.
*/

#include <iostream>
#include <matrix>
#include <ctime>
#include <iomanip>
using namespace std;

//struct contador {
//	int valor;
//	int repeticiones;
//};

int funcion(matrix<int>m, int x){
	int rep = 0;
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			if (m[i][j] == x){
				rep ++;
			}
		}
	}
	return rep;
}

//void busqueda (int val, vector<contador>&v){
//	for(size_t i=0;i<v.size();i++) { 
//		if (val == v[i].valor){
//			v[i].repeticiones ++;
//			return;
//		}
//	}
//	v.push_back({val,1});
//}

pair <int,int> funcion2 (matrix<int>m){
	int mayor1 = 0, mayor2 = 0;
	int valor1, valor2;
	vector<int>v;
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			int valor = m[i][j];
			bool yaesta = false;
			for(size_t k=0;k<v.size();k++) { 
				if (valor == v[k]){
					yaesta = true;
					break;
				}
			}
			if (yaesta == false){
				v.push_back(valor);
				int rep = funcion(m,valor);
				if (rep > mayor1) {
					mayor2 = mayor1;
					valor2 = valor1;
					mayor1 = rep;
					valor1 = valor;
				} else if (rep > mayor2) {
					mayor2 = rep;
					valor2 = valor;
				}
			}
		}
	}
	return {valor1,valor2};
}
//pair <int,int> funcion2 (matrix<int>m){
//	vector<contador>v;
//	for(size_t i=0;i<m.size(0);i++) { 
//		for(size_t j=0;j<m.size(1);j++) { 
//			busqueda(m[i][j],v);
//		}
//	}
//	int mayor1 = 0, mayor2 = 0;
//	int indice1, indice2;
//	for(size_t i=0;i<v.size();i++) { 
//		if (v[i].repeticiones > mayor1){
//			mayor2 = mayor1; indice2 = indice1;
//			mayor1 = v[i].repeticiones; indice1 = v[i].valor;
//		} else {
//			if (v[i].repeticiones > mayor2){
//				mayor2 = v[i].repeticiones; indice2 = v[i].valor;
//			}
//		}
//	}
//	return {indice1,indice2};
//}

int main() {
	srand(time(0));
	int f, c;
	cout << "Ingrese el tamaño de la matriz: " << endl;
	cout << "  - Filas: "; cin >> f;
	cout << "  - Columnas: "; cin >> c;
	matrix<int>m(f,c);
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			m[i][j] = rand () % 50 + 1;
		}
	}
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			cout << setw(3) << m[i][j] << "  ";
		}
		cout << endl;
	}
	
	pair<int,int>a = funcion2 (m);
	cout << "Los dos valores que mas se repiten son el "<<a.first<<" con "<<funcion(m,a.first)<<" veces ";
	cout << "y el "<<a.second<<" con "<<funcion(m,a.second)<<" veces";
//	pair<int,int>a = funcion2 (m);
//	int y = funcion (m, a.first);
//	int z = funcion (m, a.second);
//	cout << "Los dos valores que mas se repiten son el "<<a.first<<" con "<<y<<" veces y el "<<a.second<<" con "<<z<<" veces";
	return 0;
}

