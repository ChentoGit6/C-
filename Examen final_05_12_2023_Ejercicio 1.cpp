#include <iostream>
#include <vector>
using namespace std;
/*En análisis de sangre se considera que menos de 13.2 gramos de hemoglobina por decilitro de sangre para los hombres y menos de 11.6 g/dl 
para las mujeres implican valores bajos de glóbulos rojos y posibilidad de sufrir anemia. Considere la definición: struct paciente 
(int dni, char sexo, float hemog1, hemog2) que permite definir una estructura C++ para cada paciente de un estudio y tratamiento 
sobre anemia (hemoglobina baja) en un grupo de N personas. El miembro dni representa el documento del paciente, sexo el género (F o M),
y el valor hemog1 el valor medido de hemoglobina al inicio del estudio, hemog2 el valor al finalizar tratamiento. Un valor O de 
hemoglobina indica que ese análisis no fue realizado (suele ocurrir que algunas personas abandonaron el tratamiento y no se realizaron 
análisis). Con un solo valor cero no se debe considerar al paciente en el estudio. A) Escriba una función C++ llamada prom_hemog que 
reciba un vector de tipo paciente y devuelva dos valores; el valor promedio del valor final de hemoglobina del grupo de hombres (hemog2) 
y el mismo promedio entre las mujeres B) Escriba otra función llamada grupo_hermobaja que devuelva un único vector con los datos de 
todos los pacientes (mujeres y hombres) que a pesar del tratamiento no han aumentado los valores de hemoglobina (hemog2 menor o igual a
hemog1). C) Escriba un programa C++ cliente de ambas funciones, que lea los datos de N pacientes (N dato inicial) y muestre los resultados
de ta función prom_hemog) y los dni de los pacientes que no respondieron al tratamiento (hemog2 menor o igual a hemog1)
*/

struct paciente{
	int dni;
	char sexo;
	float hemog1,hemog2;
};
//A)Escriba una función C++ llamada prom_hemog que reciba un vector de tipo paciente y devuelva dos valores; el valor promedio del valor
//final de hemoglobina del grupo de hombres (hemog2) y el mismo promedio entre las mujeres
pair<float,float>prom_hemog(vector<paciente>v){
	float suma_hemog2_M=0, contador_hemog2_M=0;
	float suma_hemog2_F=0, contador_hemog2_F=0;
	
	for(size_t i=0;i<v.size();i++) { 
		if (v[i].sexo == 'M' || v[i].sexo == 'm'){
			if (v[i].hemog2 != 0){
				suma_hemog2_M += v[i].hemog2;
				contador_hemog2_M ++;
			}
		}else{
			if (v[i].sexo == 'F' || v[i].sexo == 'f'){
				if (v[i].hemog2 != 0){
					suma_hemog2_F += v[i].hemog2;
					contador_hemog2_F ++;
				}
		    }
	    }
	}
	float promedio_hemog_M = suma_hemog2_M / contador_hemog2_M;
	float promedio_hemog_F = suma_hemog2_F / contador_hemog2_F;
	pair<float,float>p;
	p.first = promedio_hemog_M;
	p.second = promedio_hemog_F;
	return p;
}
//B) Escriba otra función llamada grupo_hemobaja que devuelva un único vector con los datos de todos los pacientes (mujeres y hombres) 
//que a pesar del tratamiento no han aumentado los valores de hemoglobina (hemog2 menor o igual a hemog1)
vector<paciente>grupo_hemobaja(vector<paciente>v){
	
	vector<paciente>h;
	
	for(size_t i=0;i<v.size();i++) { 
		if (v[i].hemog2 <= v[i].hemog1){
			h.push_back(v[i]);
		}
	}
	return h;
}
//C) Escriba un programa C++ cliente de ambas funciones, que lea los datos de N pacientes (N dato inicial) y muestre los resultados
//de la función prom_hemog y los dni de los pacientes que no respondieron al tratamiento (hemog2 menor o igual a hemog1)
int main() {
	int N;
	cout << "Ingrese la cantidad total de pacientes: ";cin >> N;
	vector<paciente>v(N);
	for(size_t i=0;i<v.size();i++) { 
		cout << "Ingrese los datos del paciente "<< i+1 << endl;
		cout << "DNI: "; cin >> v[i].dni;
		cout << "Sexo: "; cin >> v[i].sexo;
		cout << "Nivel de hemoglobina inicial: "; cin >> v[i].hemog1;
		cout << "Nivel de hemoglobina final: "; cin >> v[i].hemog2;
	}
	
	pair<float,float>p = prom_hemog(v);
	cout << "El valor promedio del valor final de hemoglobina del grupo de hombres es: "<< p.first << endl;
	cout << "El valor promedio del valor final de hemoglobina del grupo de mujeres es: "<< p.second << endl;
	
	vector<paciente>h = grupo_hemobaja(v);
	cout << "Los DNIs de los pacientes que no respondieron al tratamiento son: "<< endl;
	for(size_t i=0;i<h.size();i++) { 
		cout << h[i].dni << " - ";
	}
	
	return 0;
}

