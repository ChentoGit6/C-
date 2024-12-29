/*Ej 1 La escudería de Fórmula 1 Búfalo Azul, está buscando un piloto para la próxima temporada, y para ello quiere 
evaluar a N candidatos que han participado en varias de las 24 competencias de la temporada actual. Escriba un programa que: 
a) Permita ingresar primero los nombres de los N pilotos que están siendo evaluados (N es dato); y permita luego ingresar los 
resultados de estos pilotos en las carreras en que participaron: por cada carrera en que participó cada piloto se ingresa una 
terna formada por número de carrera (1 a 24), número de piloto (1 a N), y posición en la que arribó. Notar que no todos los 
pilotos participaron de las 24 carreras, la carga finaliza cuando se ingresa número de carrera 0. El programa debe informar luego: 
b) Por cada piloto, la posición de arriba promedio (contando solamente las carreras en las que participó). c) Por cada carrera, 
el piloto que mejor resultado obtuvo (si en alguna carrera no compitió ninguno se la saltea) d) Cuál fue el piloto (informar el nombre) 
que más veces llegó entre los 10 primeros.
*/

#include <iostream>
#include <vector>
#include <matrix>
using namespace std;

struct top10 {
	int rep;
	int nro_piloto;
};

void busqueda (int j, vector<top10>&v){
	for(size_t i=0;i<v.size();i++) { 
		if (v[i].nro_piloto == j){
			v[i].rep ++;
			return;
		}
	}	
	v.push_back({1,j});
}

int main() {
	int N;
	cout << "Ingrese la cantidad de pilotos: "; cin >> N;
	vector<string>p(N);
	for(size_t i=0;i<p.size();i++) { 
		cout << "Nombre del piloto " << i+1 << ": "; cin >> p[i];
	}
	matrix<int>m(3,N+1,0); //25 filas, en la ultima los promedios de los pilotos
	// y N+1 columnas, en la ultima el mejor piloto de cada carrera
	int nrop, nroca, pos;
	cout << "Ingrese número de carrera: "; cin >> nroca;
	while (nroca != 0){
		cout << "Ingrese número de piloto: "; cin >> nrop;
		cout << "Ingrese la posición del piloto: "; cin >> pos;
		m[nroca-1][nrop-1] = pos;
		cout << "Ingrese número de carrera: "; cin >> nroca;
	}
	int contador = 0;
	int suma = 0;
	int sumapos = 0;
	while (contador < N){
		for(size_t i=0;i<m.size(0)-1;i++) { 
			if (m[i][contador] != 0){
				suma ++;
				sumapos += m[i][contador];
			}
		}
		m[m.size(0)-1][contador] = (sumapos / suma);
		sumapos = 0; 
		suma = 0;
		contador ++;
	}
	for(size_t j=0;j<m.size(1)-1;j++) { 
		cout << "La posición de arribo promedio del piloto " << j+1 << " es: " << m[m.size(0)-1][j] << endl;
	}	
	int mejorpos = N;
	int piloto;
	for(size_t i=0;i<m.size(0)-1;i++) { 
		for(size_t j=0;j<m.size(1)-1;j++) { 
			if (m[i][j] < mejorpos){
				mejorpos = m[i][j];
				piloto = j;
			}
		}
		m[i][m.size(1)] = piloto;
		mejorpos = N;
	}
	for(size_t i=0;i<m.size(0)-1;i++) { 
		cout << "En la carrera " << i+1 << " el mejor piloto fue: " << m[i][m.size(1)]+1 << endl;
	}
	vector<top10>v;
	for(size_t i=0;i<m.size(0)-1;i++) { 
		for(size_t j=0;j<m.size(1)-1;j++) { 
			if (m[i][j] <= 10 and m[i][j] > 0){
				busqueda(j,v);
			}
		}
	}
	int mayor = 0;
	int indice;
	for(size_t i=0;i<v.size();i++) { 
		if (v[i].rep > mayor){
			mayor = v[i].rep;
			indice = i;
		}
	}
	cout << "El piloto que mas veces llegó al top 10 en las "<< m.size(0)-1 <<" carreras es "<< p[indice];
	return 0;
}

