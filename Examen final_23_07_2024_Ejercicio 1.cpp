#include <iostream>
#include <matrix>
using namespace std;
/*Un grupo de investigación analiza el comportamiento de 120 pacientes hospitalizados y afectados por una epidemia. 
Se tomaron los valores de presión de oxigeno en sangre y de temperatura. cada 4 hs durante 7 dias (hay 6 lecturas diartas x paciente) 
a) Escriba un programa que permita ingresar estos datos sin orden alguno por cada medición se ingresan 5 datos. Nro Paciente (1 120), 
Dia Hora Valor presión oxígeno. Valor temperatura Ejemplo 108. 4. 20. 92. 356 (paciente 108, dia 4, hora 20 presión oxigeno 92, temperatura 
35.6) Organice estos datos en una tabla/matriz de dos dimensiones: 120 filas (pacientes) x 7 columnas (dias), donde en cada celda guarde la
presión de oxigeno media diaria y temperatura media diaria correspondientes (para obtener la temperatura media de un dia promedie las 
6 temperaturas obtenidas de ese dia, igual para la presión de e oxigeno) b) Calcule mediante una función que reciba un nro de paciente, 
en qué dias su temperatura media diania superó los 37 grados, c) Calcule mediante otra función cuantos pacientes tuvieron hipoxemia 
(presión media diaria de oxigeno inferior a 75) durante 2 o más dias seguidos El programa debe informar los resultados de b) para un 
paciente que Ingrese el usuario y de c)
*/

struct paciente {
	float media_ox=0, media_temp=0;
};

vector<int>temp_alta(matrix<paciente>m, int pac){
	vector<int>v;
	for(size_t i=0;i<m.size(0);i++) { 
		if (i==pac){
			for(size_t j=0;j<m.size(1);j++) { 
				if (m.media_temp > 37){
					v.push_back(j);
				}
			}
		}
	}
	return v;
}
	
int hipoxemia (matrix<paciente>m){
	int suma = 0;
	for(size_t i=0;i<m.size();i++) { 
		for(size_t j=0;j<m.size();j++) { 
			if (m[i][j].media_ox < 75 and m[i][j+1].media_ox < 75){
				suma++;
			}
		}
	}
	return suma;
}

int main() {
	matrix<paciente>m(120,7);
	int pac, dia, hora;
	float ox, temp;
	
	cout << "Ingrese el número de paciente (0 para terminar): "; cin >> pac;
	while (pac != 0){
		cout << "Ingrese los datos del paciente ingresado:"<<endl;
		cout << "Dia: "; cin >> dia;
		cout << "Hora: "; cin >> hora;
		cout << "Valor de oxígeno: "; cin >> ox;
		cout << "Valor de temperatura: "; cin >> temp;
		
		m[pac][dia].media_ox += ox/6; 
		m[pac][dia].media_temp += temp/6;
		
		cout << "Ingrese el número de paciente (0 para terminar): "; cin >> pac;
	}	
	
	cout << "Ingrese el número de un paciente para saber en que dias su temperatura media superó los 37 grados: "; cin >> pac;
	vector<int>f = temp_alta(m,pac);
	for(size_t i=0;i<f.size();i++) { 
		cout << f[i] << "  ";
	}
	
	ernes = hipoxemia(m);
	cout << "La cantidad de pacientes que su presión media diaria de oxígeno es menor a 75 es: " << ernes <<endl;
	
	return 0;
}

