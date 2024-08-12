#include <iostream>
#include <vector>
using namespace std;
/*Considere el struct postulante (string alumno; int cod. DNI, cant aprob, cant insuf, float prom para organizar los datos de un grupo de N alumnos 
(N es dato) que se postulan a una beca. El membro alumno se usará para el apellido seguido del nombre, el miembro cod para un entero entre 1 y N, 
cant aprob es la cantidad de materias aprobadas, cant insuf es la cantidad de insuficientes, prom el promedio de las materias aprobadas a) Escriba 
un programa C++ que lea los datos de los N alumnos los cuales deben organizarse en un vector v de tipo postulante. b) El programa debe leer además los 
datos de una cantidad E de exámenes (E es dato) recientemente rendidos por el grupo Por cada uno se debe leer el código de alumno (entre 1 y N) y la 
nota obtenida. Se aprueba con 6 o más. Con estos datos se debe modificar/actualizar el vector v, ya que puede cambiar la cantidad de notas aprobadas
o la cantidad de insuficientes, y cambiará el promedio de las materias aprobadas.
c) La beca solo puede ser otorgada a alumnos con más de 20 materias aprobadas y no más de 3 insuficientes. Escriba una función para generar un nuevo 
vector que contenga sólo aquellos alumnos que cumplan este requisito. Informe en el programa cliente el % de alumnos que quedan fuera de la lista. 
d) Determine a través de otra función los 2 alumnos con mejor promedio (entre los que cumplen los requisitos de c) e informe sus datos (nombre, dni y 
promedio) en el programa principal Ayuda para actualizar el promedio: si un alumno tiene promedio P y cantidad de materias aprobadas C. entonces la 
suma de sus notas por las materias aprobadas es P°C. Al agregar una nueva nota N, el nuevo promedio será (PC+N)/(C+1).
*/

struct postulante{
	string alumno;
	int cod, DNI, cant_aprob, cant_insuf;
	float prom;
};

vector<string> beca (vector<postulante>v){
	vector<string>b;
	for(size_t i=0;i<v.size();i++) { 
		if (v[i].cant_aprob >= 20 and v[i].cant_insuf <= 3){
			b.push_back (v[i].alumno);
		}
	}
	return b;
}

pair<postulante,postulante> DosMjs (vector<postulante>v){
	int m1=0, m2=0;
	postulante mej1, mej2;
	for(size_t i=0;i<v.size();i++) { 
		if (v[i].prom > m1){
			m2 = m1; mej2 = mej1;
			m1 = v[i].prom; mej1 = v[i];
		} else {
			if (v[i].prom > m2){
				m2 = v[i].prom; mej2 = v[i];
			}
		}
	}
	pair<postulante,postulante>p;
	p.first = mej1;
	p.second = mej2;
	return p;
}
	
int main() {
	int N;
	cout << "Ingrese la cantidad de postulantes: ";cin >> N;
	vector<postulante>v(N);
	for(size_t i=0;i<v.size();i++) { 
		cout << "Ingrese los datos del alumno "<< i+1 <<endl;
		cout << "Apellido y Nombre: ";cin >> v[i].alumno;
		cout << "Código: ";cin >> v[i].cod;
		cout << "DNI: ";cin >> v[i].DNI;
		cout << "Cantidad de materias aprobadas: ";cin >> v[i].cant_aprob;
		cout << "Cantidad de insuficientes: ";cin >> v[i].cant_insuf;
		cout << "Promedio de las materias aprobadas: ";cin >> v[i].prom;
	}
	int E;
	cout << "Ingrese la cantidad de exámenes rendidos recientemente por el grupo: "; cin >> E;
	int codigo, nota;
	for(int i=0; i<E; i++) {
		cout << "Exámen " << i + 1<< ": " << endl;
		cout << "Ingrese el código del alumno para cargar su nota (0 para terminar): "; cin >> codigo;
		while(codigo != 0){
			cout << "Ingrese la nota: "; cin >> nota;
			if (nota >= 6){
			    v[codigo-1].prom = (v[codigo-1].prom * v[codigo-1].cant_aprob + nota) / (v[codigo-1].cant_aprob + 1);
				v[codigo-1].cant_aprob ++;
			} else {
				v[codigo-1].cant_insuf ++;
			}
			cout << "Ingrese el código del alumno para cargar su nota (0 para terminar): "; cin >> codigo;
		}
	}	
	cout << "Los alumnos que se les otroga la beca son: " << endl;
	vector<string>bec = beca(v);
	int suma = 0;
	for(size_t i=0;i<bec.size();i++) { 
		cout << bec[i] << " , " ;
		suma += 1;
	}
	cout << endl;
	float porc = (100-(suma/N*100));
	cout << "El % de alumnos que se quedan fuera de la lista es: " << porc << "%" << endl; 
	
	pair<postulante,postulante>p = DosMjs(v);
	cout << "Los dos alumnos con mejor promedio  son: " << endl;
	cout << "1º: " << p.first.alumno << " - " << p.first.DNI << " - prom: " << p.first.prom <<endl;
	cout << "2º: " << p.second.alumno << " - " << p.second.DNI << " - prom: " << p.second.prom <<endl;
	
	return 0;
}

