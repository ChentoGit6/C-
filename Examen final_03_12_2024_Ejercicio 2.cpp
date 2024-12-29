/*Ej 2 a) Defina un struct para guardar el dni, las notas de dos parciales y el nombre de un alumno. b) Escriba una función que reciba un vector 
con los datos de varios alumnos, el nombre de un alumno, una nota y un entero para indicar si corresponde al 1er o 2do parcial. 
La función debe buscar al alumno en el vector y reemplazar la nota solo si la que recibe es mayor a la que tenía previamente. 
Si el alumno no está en el vector, la función debe agregarlo con esa nota en el parcial que corresponda y -1 en el otro. 
c) Escriba un programa cliente que permita cargar ternas (nombre, nro de parcial, nota) que se vayan organizando en un vector mediante 
la el struct a a) y la función de b) (se desconoce a priori la cantidad), y luego informe el nombre y el promedio final de cada alumno 
si tiene nota en ambos parciales; o si le falta una de las notas muestre el mensaje "no rindió" en lugar del promedio.
*/

#include <iostream>
#include <vector>
using namespace std;

struct alumno {
	string nombre;
	int dni;
	float nota1, nota2;
};

void funcion (vector<alumno>&v, string nombre, int nota, int nro, int DNI){
	bool encontro = false;
	for(size_t i=0;i<v.size();i++) { 
		if (nombre == v[i].nombre){
			encontro = true;
			if (nro == 1){
				if (nota > v[i].nota1){
					v[i].nota1 = nota;
				}
			} else {
				if (nota > v[i].nota2){
					v[i].nota2 = nota;
				}
			}
			break;
		}
	}
	if (encontro == false){
		alumno a;
		a.nombre = nombre;
		a.dni = DNI;
		if (nro == 1){
			a.nota1 = nota;
			a.nota2 = -1;
		} else {
			a.nota2 = nota;
			a.nota1 = -1;
		}
		v.push_back(a);
	}
}

int main() {
	vector<alumno>v;
	string nombre_alu;
	int DNI;
	float nota;
	int nro;
	cout << "Ingrese el nombre del alumno: "; cin >> nombre_alu;
	while (nombre_alu != "fin"){
		cout << "Ingrese el dni del alumno: "; cin >> DNI;
		cout << "Ingrese el número del parcial (1 o 2): "; cin >> nro;
		cout << "Ingrese la nota del parcial " << nro << ": " ; cin >> nota;
		funcion (v,nombre_alu,nota,nro,DNI);
		cout << "Ingrese el nombre del alumno: "; cin >> nombre_alu;
	}
	for(size_t i=0;i<v.size();i++) { 
		cout << v[i].nombre << " - " << v[i].dni << endl;
		cout << "  - Nota 1: " << v[i].nota1 << endl;
		cout << "  - Nota 2: " << v[i].nota2 << endl;
		if (v[i].nota1 == -1 || v[i].nota2 == -1){
			cout << "  - Resultado: no rindió" << endl;
		} else {
			cout << "  - Promedio: " << (v[i].nota1 + v[i].nota2) / 2 << endl;
		}
	}
	
	return 0;
}

