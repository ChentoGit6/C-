#include <iostream>
#include <vector>
using namespace std;
/*En una competencia universitaria de matemáticas se han presentado 24 equipos de diferentes universidades (codificados 1..24) que deben
resolver 9 ejercicios en el menor tiempo posible. No todos los equipos llegan a completar los ejercicios, dejando algunos sin resolver. Resulta 
triunfador el equipo que más problemas resuelve; en caso de empate en la cantidad de problemas gana el equipo que empleó menos tiempo en total.
Considere la estructura Equipo (string univ; vector<int> tiempos(9); int cant_aprob:); donde univ es el nombre de la universidad, tiempos es un vector
que guarda el tiempo en minutos empleado en cada ejercicio (0 si está mal resuelto o no fue realizado), cant aprob es la la cantidad de ejercicios
bien resueltos.- Diseñe una función C++ que reciba un vector de tipo Equipo con todos los datos de la competencia y devuelva los dos mejores equipos.
No se requiere hacer el programa cliente.
*/

struct Equipo{
	string univ;
	vector<int>tiempos;
	int cant_aprob;
};

bool supera (Equipo a, Equipo b){
	if (a.cant_aprob > b.cant_aprob) return true;
	if (a.cant_aprob < b.cant_aprob) return false;
	if (a.cant_aprob == b.cant_aprob){
		int suma1=0,suma2=0;
		for(size_t i=0;i<a.tiempos.size();i++) { 
			suma1 += a.tiempos[i]; 
			suma2 += b.tiempos[i];
			if (suma1 > suma2) return true;
			if (suma1 < suma2) return false;
		}
	}	
	return false;
}

pair<int,int>obtener_ganadores(vector<Equipo>&v){
	int pos_mayor=0, pos_seg=1;/*mejor_equipo1, mejor_equipo2, mayor1=-1, mayor2=-1*/
	if (supera(v[1],v[0])) swap(pos_mayor,pos_seg);
	for(size_t i=2;i<v.size();i++) { 
		if (supera (v[i], v[pos_mayor])){
		pos_seg = pos_mayor; pos_mayor = i;
		}else{
			if (supera (v[i], v[pos_seg])){
				pos_seg = i;
			}
		}
	}
	pair<int,int>p;
	p.first = pos_mayor;
	p.second = pos_seg;
	return p;
}

int main() {
	
	return 0;
}

