/*Ej3 Una materia tiene 4 evaluaciones codificadas: 1 (parcial 1),2 (recup. parcial 1),3 (parcial 2),4 (recup.
parcial 2). El Profesor responsable de la materia -en la que hay muchos docentes- quiere saber quién corrigió cada
parcial o recuperatorio de su materia. a) Escriba un programa que permita ingresar la cantidad de alumnos de la
materia (N), y luego ternas de datos: nro de alumno (1 a N), nro de evaluación (1 a 4), y nombre del docente que lo
corrigió. Los datos finalizan con el nro de alumno -1 (porque no todos los alumnos rindieron las 4 instancias).
Organice estos datos en una matriz de N filas x 4 columnas, donde cada casillero contenga el nombre del docente
que corrigió un parcial/recuperatorio, o la cadena "No rindió" si el alumno no se presentó a esa evaluación. b) El
programa debe luego informar cuántos alumnos rindieron cada evaluación; c) mostrar la lista de alumnos que no
rindieron ninguna de las (4) instancias; y d) permitir al usuario ingresar el nombre de un docente y mostrar cuántos
parciales/recuperatorios corrigió ese docente.
*/

#include <iostream>
#include <matrix>
using namespace std;

int main() {
	int N;
	cout << "Ingrese la cantidad de alumnos de la materia: "; cin >> N;
	matrix<string>m(N,4,"No rindió");
	int numa, nume;
	string docente;
	cout << "Ingrese número de alumno: "; cin >> numa;
	while (numa != -1){
		cout << "Ingrese número de evaluación: "; cin >> nume;
		cout << "Ingres el docente que corrigió: "; cin >> docente;
		m[numa-1][nume-1] = docente;
		cout << "Ingrese número de alumno: "; cin >> numa;
	}
	vector<int>v(4,0);
	for(size_t j=0;j<m.size(1);j++) { 
		for(size_t i=0;i<m.size(0);i++) { 
			if (m[i][j] != "No rindió" ){
				v[j] ++;
			}
		}
	}	
	cout << "La cantidad de alumnos que rindieron fueron: " << endl;
	for(size_t i=0;i<v.size();i++) { 
		cout << "Evaluación " << i+1 << ": " << v[i] << endl;
	}
	int cont = 0;
	cout << "Los alumnos que no rindieron ninguno de los 4 examenes son (numero de alumno): ";
	for(size_t i=0;i<m.size(0);i++) { 
		if (m[i][cont] == "No rindió" and m[i][cont+1] == "No rindió" and m[i][cont+2] == "No rindió" and m[i][cont+3] == "No rindió"){
			cout << i << "  ";
		}
	}
	cout << endl;
	string d;
	cout << "Ingrese el nombre del docente para ver la cantidad de parciales que corrigio: "; cin >> d;
	int suma = 0;
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			if (m[i][j] == d){
				suma ++;
			}
		}
	}
	cout << d << " corrigió " << suma << " examenes";
	return 0;
}

