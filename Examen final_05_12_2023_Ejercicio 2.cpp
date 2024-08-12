#include <iostream>
#include <vector>
#include <matrix>
using namespace std;
/* En una materia la regularidad se logra aprobando 8 trabajos prácticos (TPs). Por cada TP, hay una clase prevista para que los alumnos los 
presenten, pero si un alumno no llega a tiempo, puede presentarlo luego en otra clase posterior. Los tps no llevan nota, el resultado es 
simplemente aprobado o no aprobado. El docente quiere llevar registro de los tps aprobados por cada alumno y obtener ciertos resultados. 
Para ello necesita un programa que: 
A) Permita ingresar la cantidad de alumnos (N), y la fecha de entrega de cada uno de los 8 TPs
B) Permita ingresar la lista de tps defendidos y aprobados por sus un alumnos por ternas: nro de TP (1 a 8), nro de alumno (1 a N) y fecha en
la que lo aprueba. Se desconoce a priori la cantidad de ternas, los datos finalizan cuando se ingresa nro de TP 0. El programa debe organizar
estos datos en una matriz de Nx8 donde el elemento ij contiene la fecha en que el alumno j aprobó el TP i, o 0 si no lo aprobó
El programa debe informar luego: C) La lista de nros de alumnos que aprobaron todos los TPS D) Por cada TP. el % de alumnos que lo aprobó en 
la fecha prevista para ese tp, respecto al total que lo aprobó (en cualquier fecha, pero sin contar los que no lo aprobaron), E) Cuáles son 
los dos TPs que menos alumnos lograron aprobar. Nota: considere cada fecha como un solo dato numérico con el formato aaaammdd.
*/
int main() {
/*A) Permita ingresar la cantidad de alumnos (N), y la fecha de entrega de cada uno de los 8 TPs*/
	int N;
	cout << "Ingrese la cantidad de alumnos: "; cin >> N;
	vector<int>tps(8,0);
	for(size_t i=0;i<tps.size();i++) { 
		cout << "Ingrese la fecha de entrega en formato aaaammdd del Tp " << i + 1<<": "; cin >> tps[i];
	}
	//B)
	matrix<int>m(8,N,0);
	int tp, nro, fecha;
	cout << "Ingrese el nro de Tp: "; cin >> tp;
	while (tp != 0){
		cout << "Ingrese el nro de alumno: "; cin >> nro;
		cout << "Ingrese la fecha en la que el alumno "<< nro <<" aprobó el tp "<< tp <<" o 0 si no lo aprobó: "; cin >> fecha;
		m[tp-1][nro-1] = fecha;
	}
//C) La lista de nros de alumnos que aprobaron todos los TPS
	vector<int>alum_aprob;
	
	for(size_t j=0;j<m.size(1);j++) { 
		int contador = 0;
		for(size_t i=0;i<m.size(0);i++) { 
			if (m[j][i] != 0){
				contador ++;
				if (contador = 8){
					alum_aprob.push_back(j);
				}
			}
		}
	}
	cout << "Los alumnos que aprobaron todos los Tps son: "<< endl;
	for(size_t i=0;i<alum_aprob.size();i++) { 
		cout << alum_aprob[i] <<"  ";
	}
	
//D) Por cada TP. el % de alumnos que lo aprobó en la fecha prevista para ese tp, respecto al total que lo aprobó (en cualquier fecha, pero sin contar 
//los que no lo aprobaron)
	int suma, suma2;
	for(size_t i=0;i<m.size(0);i++) { 
		suma = 0;
		suma2= 0;
		for(size_t j=0;j<m.size(1);j++) { 
			if (m[i][j] == tps[i]){
				suma ++;
				suma2++;
			} else {
				if (m[i][j] != tps[i] and m[i][j] != 0){
					suma2 ++;
				}
			}
		}
		
	}
	int porc = (suma/suma2)*100;
	cout << "El % de alumnos que lo aprobó en la fecha prevista para ese tp, respecto al total que lo aprobó es: "<< porc << endl;

//E) Cuáles son los dos TPs que menos alumnos lograron aprobar. Nota: considere cada fecha como un solo dato numérico con el formato aaaammdd.
	
	vector<int>tps2(8,0);
	for(size_t i=0;i<m.size(0);i++) { 
		
		for(size_t j=0;j<m.size(1);j++) { 
			if (m[i][j] == 0){
				tps2[i] ++;
			}
		}
	}
	int menor1 = tps2[0], menor2 = tps2[0], tepe = 0, tp2;
	for(size_t i=0;i<tps2.size();i++) { 
		if (tps2[i] < menor1){
			menor2 = menor1; tp2 = tepe;
			menor1 = tps2[i]; tepe = i;
		} else {
			if (tps2[i] < menor2){
				menor2 = tps2[i]; tp2 = i;
			}
		}
	}
	cout << "Los dos TPs que menos alumnos lograron aprobar son el "<< menor1 <<" y el "<< menor2 << endl;
	
	return 0;
}




