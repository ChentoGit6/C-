#include <iostream>
#include <matrix>
#include <vector>
using namespace std;

struct candidato {
	string nombre;
	int cod_part;
}; 

struct mesas {
	int nro_mesa;
	int cod_dep;
	vector<int>votos;
};

matrix<int> totalvotos (vector<mesas>f){
	matrix<int>a(11,19,0);
	for(size_t i=0;i<f.size();i++) { 
		for(size_t j=0;j<a.size(0);j++) { 
			a[j][f[i].cod_dep] += f[i].votos[j]; 
		}
	}
	return a;
}
	
	string buscar (vector<candidato>v, int cod_part){
		for(size_t i=0;i<v.size();i++) { 
			if (v[i].cod_part == cod_part){
				return v[i].nombre;
			}
		}
		return "nada";
	}

pair<candidato,float> ganador (matrix<int>m, vector<candidato>v){
	vector<int>suma(11,0);
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			suma[i] += m[i][j];
		}
	}
	int mayor = 0;
	int cod_part;
	for(size_t i=0;i<suma.size();i++) { 
		if(suma[i] > mayor){
			mayor = suma[i];
			cod_part = i;
		}
	}
	int total = 0;
	for(size_t i=0;i<suma.size();i++) { 	
		total += suma[i];
	}
	int ganadorvotos = mayor/total * 100;
	string gobernador = buscar(v,cod_part);
	candidato c = {gobernador,cod_part};
	pair<candidato,float>p;
	p.first = c;
	p.second = ganadorvotos;
	return p;
}



int main() {
	vector<candidato>v(11);
	for(size_t i=0;i<v.size();i++) {
		cout << "Ingresa el nombre del candidato y el cod. de su partido:" << endl;
		cin >> v[i].nombre;
		cin >> v[i].cod_part;
	}
	
	int cont = 0;
	vector<mesas>f(4892);
	cout << "Ingrese el nro de mesa: " << endl;
	cin >> f[cont].nro_mesa;
	while (cont < f.size()){
		cout << "Ingrese el cod. del departamento: " << endl;
		cin >> f[cont].cod_dep;
		int p;
		for(size_t i=0;i<11;i++) { 
			cout << "Ingrese los votos válidos de los partidos en ese departamento: " << endl;
			cout << "Partido " << i << ": " << endl;
			cin >> p;
			f[cont].votos.push_back(p);
		}
		cont ++;
		cout << "Ingrese el nro de mesa: " << endl;
		cin >> f[cont].nro_mesa;
	}
	
	matrix<int>m = totalvotos(f);
	
	pair<candidato,float>p = ganador(m,v);
	cout << "El próximo gobernador es " << p.first.nombre << "con código de partido " << p.first.cod_part;
	cout << " y con un porcentaje de votos de " << p.second << "%";
	return 0;
}

