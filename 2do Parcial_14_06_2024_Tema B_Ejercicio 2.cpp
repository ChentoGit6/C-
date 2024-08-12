#include <iostream>
#include <vector>
using namespace std;
/*(30 pts) Se desea procesar los movimientos del Túnel SubFluvial a lo largo de un día. Por el túnel
pasan 5 tipos de vehículos: 1-Motos, 2-Autos, 3-Furgones, 4-Camiones, 5-Colectivos. Cada uno de estos
tipos tienen un costo diferente. a) Escriba un programa que permita ingresar primero el costo para cada
una de las 5 categorías; b) y luego pares de datos: tipo de vehículo (1 a 5) y destino (“P” a Paraná y “S”
a Santa Fe). La carga finaliza cuando se ingresa tipo de vehículo 0. Luego el programa debe informar: c)
La cantidad de vehículos registrados por cada tipo y destino. d) Los dos tipos de vehículos que más
pasaron hacia un destino ingresado por el usuario. e) La recaudación total de cada destino. Nota: Utilice
funciones para los items c), d) y e)
*/

//if (v[i].destino == 'P'){
//	registro[i].contador_p++;
//	registro[i].tipo = v[i].tipo;
//}
struct vehiculo{
	int tipo;
	char destino;
};

struct registro{
	int tipo;
	int contador_p;
	int contador_s;
};

vector<registro> analizar(vector<vehiculo>v){
	registro cero;
	cero.tipo = 0;
	cero.contador_p = 0;
	cero.contador_s = 0;
	vector<registro>f(6, cero);
	for(size_t i=0;i<v.size();i++) { 
		f[v[i].tipo].tipo +=1;
		if(v[i].destino == 'P'){
			f[v[i].tipo].contador_p++;
		}else if (v[i].destino == 'S') { // Asegúrate de que el destino sea 'S'
			f[v[i].tipo].contador_s++;
		}
	}
	return f;
}
	


int main() {
//	float motos, autos, furgones, camiones, colectivos;
//	cin >> motos >> autos >> furgones >> camiones >> colectivos;
//	
//	vector<vehiculo>v;
//	vehiculo p;
//	int tipo;
//	char destino;
//	cin >> tipo;
//	while(tipo != 0){
//		cin >> destino;
//		p.tipo = tipo;
//		p.destino = destino;
//		v.push_back(p);
//	}
//	
//	vector<registro>ernemilia = analizar(v);
//	
//	for(size_t i=1;i<ernemilia.size();i++) { 
//		cout << "La cantidad de vehiculos de tipo: "<<i<< " son: "<< ernemilia[i].tipo<<endl;
//		cout << "Donde: "<< ernemilia[i].contador_p << " fueron a Parana y " << ernemilia[i].contador_p <<" a Santa Fe"<<endl; 
//	}
//	
	return 0;
}

