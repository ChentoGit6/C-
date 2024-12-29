/*Ejercicio 2 (25pts) La Fórmula 1 está buscando mejorar la seguridad agregando nuevos elementos para proteger
las cabezas de los pilotos. Se probaron tres sistemas: el "shield" (una especie de "parabrisas" blindado), el "halo"
(un armazón de carbono) y el "ghost" (sin piloto en el auto, manejado con control remoto). Ciertos equipos han
probado algunos de estos elementos y han calificado los resultados en una escala de 1 a 5 estrellas. Se requiere
un programa C++ para analizar estos datos y ayudar a decidir cuál es la mejor opción. a) Se ingresan ternas de
datos compuestas por un código de equipo (de 1 a 10), un código de sistema (1-shield, 2-halo, 3-ghost), y la
calificación (1 a 5 estrellas). Los datos finalizan con código de equipo 0. Organice estos datos en una matriz de
10x3 (10 equipos, 3 sistemas), donde cada posición debe guardar la cantidad de estrellas asignadas por ese
equipo a ese sistema, o -1 si ese equipo no probó ese sistema. b) muestre solo los equipos que calificaron los tres
sistemas, con sus respectivas calificaciones. c) Informe el nombre del sistema que obtuvo un mayor promedio de
estrellas (el promedio se calcula considerando todos los equipos que probaron el sistema, sin considerar los -1).
Defina y utilice para ello una función calcular_promedio que calcule el promedio de un sistema.
*/

#include <iostream>
#include <matrix>
#include <vector>
using namespace std;

struct sist_prom {
	int num;
	float prom;
};

float calcular_promedio (matrix<int>m, int a){
	int cant_es = 0, cant_sin1 = 0;
	for(size_t i=0;i<m.size(0);i++) {  
		if (m[i][a] != -1){
			cant_es += m[i][a];
			cant_sin1 ++;
		}
	}
	return (cant_es / cant_sin1);
}

int main() {
	matrix<int>m(2,3,-1);
	int cod_equ, cod_sist, cal;
	vector<string>v = {"Shield","Halo","Ghost"};
	cout << "Ingrese código de equipo: "; cin >> cod_equ;
	while (cod_equ != 0){
		cout << "Ingrese código de sistema: "; cin >> cod_sist;
		cout << "Ingrese la calificación: "; cin >> cal;
		m[cod_equ - 1][cod_sist - 1] = cal;
		cout << "Ingrese código de equipo: "; cin >> cod_equ;
	}
	int cont = 0;
	cout << "Los equipos que calificaron los 3 equipos son: " << endl;
	for(size_t i=cont;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			if (m[i][j] != -1 and m[i][j+1] != -1 and m[i][+2] != -1){
				cout << "Equipo " << i+1 << ":" << endl;
				cout << "  -Shield : " << m[i][j] << " estrellas" << endl;
				cout << "  -Halo : " << m[i][j+1] << " estrellas" << endl;
				cout << "  -Ghost : " << m[i][j+2] << " estrellas" << endl;
				
			}
			break;
		}
		cont ++;
	}
	vector<float>f(3);
	for(size_t i=0;i<f.size();i++) { 
		f[i] = calcular_promedio (m,i);
	}
	float mayor = 0;
	int indice;
	for(size_t i=0;i<f.size();i++) { 
		if (f[i] > mayor){
			mayor = f[i];
			indice = i;
		}
	}
	cout << "El sistema que obtuvo un mayor promedio de estrellas es el " << v[indice] << " con " << mayor << " estrellas";
	return 0;
}

