#include <iostream>
#include <vector>
using namespace std;

struct componentes {
	int cod_comp;
	float factor;
};

struct pais {
	string nombre;
	string continente;
	vector<componentes>f;
	float idh;
};

int supera90 (vector<pais>p, int C){
	int cont = 0;
	for(size_t i=0;i<p.size();i++) { 
		if (p[i].f[C-1].factor > 90){
			cont++;
		}
	}	
	return cont;
}

int main() {
	cout << "Ingrese los codigos de los componentes y sus respectivos factores para el IDH: " << endl;
	vector<componentes>v(15);
	for(size_t i=0;i<v.size();i++) { 
		cout << "Código: ";
		cin >> v[i].cod_comp;
		cout << "Factor: ";
		cin >> v[i].factor;
	}
	int N;
	componentes a;
	cout << "Ingrese la cantidad de países: "; cin >> N; 
	vector<pais>p(N);
	for(size_t i=0;i<p.size();i++) { 
		cout << "Ingrese el nombre del país: "; cin >> p[i].nombre;
		cout << "Ingrese el continente del país: "; cin >> p[i].continente;
		cout << "Ingrese los codigos de los componentes y sus respectivos factores para "<< p[i].nombre <<" :"<< endl;
		for(int j=0;j<15;j++) { 
			cout << "Código: ";
			cin >> a.cod_comp;
			cout << "Factor: ";
			cin >> a.factor;
			p[i].f.push_back(a);
		}  
	}
	float suma = 0;
	for(size_t i=0;i<p.size();i++) { 
		for(int j=0;j<15;j++) { 
			suma += p[i].f[j].factor * v[j].factor;
		}
		p[i].idh = suma;
		suma = 0;
	}
	int C;
	cout << "Ingrese una componente que quiera saber cuantos paises la superan en 90: "; cin >> C;
	int carlucci = supera90(p,C);
	cout << carlucci << " países superan 90 en la componente " << C << endl;
	
	return 0;
}

