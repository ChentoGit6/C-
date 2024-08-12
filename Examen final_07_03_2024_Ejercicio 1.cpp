#include <iostream>
#include <matrix>
#include <vector>
using namespace std;
/*En una fábrica, se procesan chapas de espesor fijo para producir piezas rectangulares de dimensiones a y b (a: ancho y b largo, datos iniciales). 
La fábrica tiene 8 máquinas que fabrican estas piezas y deben descartarse aquellas cuyas dimensiones difieran en +-2% en los valores de a y/o de b.
Escriba un programa C++ que analice la calidad de las piezas producidas en un mes (30 dias). a) Debe leer primero las medidas a y b de las piezas que 
se quieren producir, y luego cuaternas de datos de cada pieza fabricada: da, db, cod maq, dia, siendo da y db los valores del ancho y del largo de
la pieza fabricada, cod maq el número de máquina (1... 8) que la produjo, y dia es el número de dia en el mes (1..31). Estos datos finalizan con 
cod maq 0. El programa debe organizar una tabla o matriz de al menos 8 filas (maquinas) por 31 columnas (días del mes) donde cada celda registre 
2 valores: cantidad de piezas aceptadas y cantidad de piezas rechazadas. b) Proponga una función que retome la mayor cantidad de fallos en un día y 
el día que se produjeron. c) Proponga otra función que retome la máquina que posee menos piezas con fallos en todo el mes y el % de piezas fallada
sobre el total que esa máquina produce en el mes. Utilice las funciones de b y c en el programa e informe todos los resultados.
*/
struct piezas {
	int piezasaceptadas,piezasrechazadas;
};

pair<int,int>mayorfallo(matrix<piezas>registracion){
	vector<int>v(registracion.size(1));
	for(size_t j=0;j<registracion.size(1);j++) { 
		int suma=0;
		for(size_t i=0;i<registracion.size(0);i++) {
			suma += registracion[i][j].piezasrechazadas;
			v[j]=suma;
		}
	}
	int mayor=-1;
	int diamayor;
	for(size_t j=0;j<v.size();j++) { 
		if (v[j]>mayor){
			mayor=v[j];
			diamayor=j;
		}
	}
	pair<int,int>p;
	p.first = mayor;
	p.second = diamayor;
	return p;
}
	
pair<int,float>maquina_con_menos_fallos(matrix<piezas>registracion){
	vector<int>rechazadas(registracion.size(0));
	vector<int>aceptadas(registracion.size(0));
	for(size_t i=0;i<registracion.size(0);i++) {
		int suma1=0;
		int suma2=0;
		for(size_t j=0;j<registracion.size(1);j++) { 
			suma1 += registracion[i][j].piezasrechazadas;
			suma2 += registracion[i][j].piezasaceptadas;
			rechazadas[i]=suma1;
			aceptadas[i]=suma2;
		}	
	}
	int menorpiezasfalladas = 999999;
	int maq;
	int sumatotalpiezas=0;
	for(size_t i=0;i<rechazadas.size();i++) { 
		if (rechazadas[i]<menorpiezasfalladas){
			menorpiezasfalladas = rechazadas[i];
			sumatotalpiezas = menorpiezasfalladas + aceptadas[i];
			maq = i-1;
			
		}
		
	}
	float porcentaje_falladas;
	if (sumatotalpiezas > 0){
		porcentaje_falladas = (menorpiezasfalladas / sumatotalpiezas)*100;
	}
	pair<int,float>f;
	f.first = maq;
	f.second = porcentaje_falladas;
	return f;
}

int main() {
	cout << "Ingrese las medidas a y b de las piezas que se quieren producir (a: ancho y b: largo):"<<endl;
	float a,b;
	cout << "a: ";cin >> a;
	cout << "b: ";cin >> b;;

	matrix<piezas>registracion(8,31);
	
	float da,db; int cod_maq,dia;
	cout << "Ingresa el código de máquina: "; cin >> cod_maq;
	while (cod_maq != 0){
		cout << "Ingresa las medidas a y b de la pieza que produjo la máquina " << cod_maq << ": ";
		cout << "a: ";cin >> da;
		cout << "b: ";cin >> db;
		cout << "Ingrese el día en el que se produjeron: "; cin >> dia;
		
		if ((da >= a * 0.98 && da <= a * 1.02) && (db >= b * 0.98 && db <= b * 1.02)) {
			registracion[cod_maq - 1][dia - 1].piezasaceptadas++;
		} else {
			registracion[cod_maq - 1][dia - 1].piezasrechazadas++;
		}
		
		cout << "Ingresa el código de máquina: "; cin >> cod_maq;
	}
	
	for (size_t i = 0; i < registracion.size(0); i++) {
		for (size_t j = 0; j < registracion.size(1); j++) {
			cout << "Máquina " << i + 1 << ", Día " << j + 1;
				cout<< " - Aceptadas: " << registracion[i][j].piezasaceptadas << ", Rechazadas: " << registracion[i][j].piezasrechazadas << endl;
		}
	}
	
	pair<int,int>p = mayorfallo(registracion);
	cout << "El dia con mayor fallos fue el "<<p.second+1<<" con un total de "<<p.first<< " piezas rechazadas"<<endl;
	
	pair<int,float>f = maquina_con_menos_fallos(registracion);
	cout << "La maquina que tuvo menos piezas con fallos a lo largo del mes fue la "<<f.first+1;
	cout << " y el % de piezas fallada sobre el total que esa máquina produce en el mes es del "<<f.second<<"%"<<endl;
	return 0;
}

