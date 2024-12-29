/*Ej2 El código fuente de un proyecto de software muy grande está dividido en muchos archivos. Se desea
analizar la longitud de cada uno y del proyecto completo. a) Escriba un programa que permita cargar por cada uno
de los N (dato) archivos 3 valores: nombre, cantidad de líneas de código, cantidad de funciones que define; y guarde
toda esta información en un único vector. b) Luego debe informar por cada archivo el promedio de líneas por
función; c) los nombres de los dos archivos con más líneas de código; y d) las cantidades totales de líneas y de
funciones sumando todos los archivos. Importante: Resuelva implementando una función para cada uno de los ítems
c) y d) que calcule lo que se requiere informar desde el programa principal (main).
*/

#include <iostream>
#include <vector>
using namespace std;

struct archivo {
	string nombre;
	int cant_linea_cod;
	int cant_fun_def;
};

pair <string,string> maslineas (vector<archivo>v){
	int mayor1 = 0, mayor2 = 0;
	string nom1, nom2;
	for(size_t i=0;i<v.size();i++) { 
		if (v[i].cant_linea_cod > mayor1){
			mayor2 = mayor1; nom2 = nom1;
			mayor1 = v[i].cant_linea_cod; nom1 = v[i].nombre;
		} else if (v[i].cant_linea_cod > mayor2){
			mayor2 = v[i].cant_linea_cod;
			nom2 = v[i].nombre;
		}
	}
	return {nom1,nom2};
}

pair <int,int> cant_lin_fun (vector<archivo>v){
	int sumal = 0;
	int sumaf = 0;
	for(size_t i=0;i<v.size();i++) { 
		sumal += v[i].cant_linea_cod;
		sumaf += v[i].cant_fun_def;
	}
	return {sumal,sumaf};
}

int main() {
	int N;
	cout << "Ingrese la cantidad de archivos: "; cin >> N;
	vector<archivo>v(N);
	for(size_t i=0;i<v.size();i++) { 
		cout << "Ingrese nombre del archivo: "; cin >> v[i].nombre;
		cout << "Cantidad de lineas de codigo: "; cin >> v[i].cant_linea_cod;
		cout << "Cantidad de funciones que define: "; cin >> v[i].cant_fun_def;
	}
	cout << endl;
	cout << "El promedio de líneas por función de cada archivo:" << endl;
	for(size_t i=0;i<v.size();i++) { 
		cout << "Archivo " << v[i].nombre << ": " << (v[i].cant_linea_cod / v[i].cant_fun_def) << endl;
	}
	cout << endl;
	pair <string,string> p = maslineas (v);
	cout << "Los dos archivos con mas lineas de codigo son " << p.first << " y " << p.second << endl;
	pair <int,int> q = cant_lin_fun (v);
	cout << endl;
	cout << "La cantidad de lineas totales son " << q.first << " y la cantidad de funciones totales es " << q.second;
	return 0;
}

