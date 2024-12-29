#include <iostream>
#include <vector>
using namespace std;
struct Kw{
	int n;
	float pbaseKw, pKwsuperaTope;
	int topeKw;
};
struct usuario {
	int nro, kwcons;
	string tipo;
	Kw monto;
};

void funcion2 (vector<usuario>epe, vector<Kw>t){
	vector<int>totalkw(5);
	for(size_t i=0;i<epe.size();i++) { 
		
	}
}

pair<int,float> funcion (vector<usuario>epe, vector<Kw>t, int a){
	int contkw = 0;
	int difkw = 0;
	float total$kwcons = 0;
	float total$kwsupera = 0;
	float totalmontoKw = 0;
	vector<usuario>z;
	for(size_t i=0;i<epe.size();i++) { 
		if (epe[i].nro == a){
			contkw += epe[i].kwcons;
			z.push_back(epe[i]);
		} 
	}
	for(size_t i=0;i<z.size();i++) { 
		if (z[i].kwcons <= t[a-1].topeKw){
			total$kwcons += z[i].kwcons * t[a-1].pbaseKw;
		}
		if (z[i].kwcons > t[a-1].topeKw){
			difkw = z[i].kwcons - t[a-1].topeKw;
			total$kwsupera += difkw * t[a-1].pKwsuperaTope;
			total$kwcons += t[a-1].topeKw * t[a-1].pbaseKw;
		}
	}
	totalmontoKw = total$kwcons + total$kwsupera;
	pair<int,float>rta;
	rta.first = contkw;
	rta.second = totalmontoKw;
	return rta;
}

int main() {
	Kw tipo;
	vector<Kw>t(5);
	for(size_t i=0;i<t.size();i++) { 
		cout << "Ingrese los datos del tipo de usuario "<< i+1 <<endl;
		cout << "Tipo: "; cin >> tipo.n;
		cout << "Precio base Kw: "; cin >> tipo.pbaseKw;
		cout << "Precio Kw supera tope: "; cin >> tipo.pKwsuperaTope;
		cout << "Tope Kw: "; cin >> tipo.topeKw;
		t[i] = tipo;
	}
	vector<usuario>epe;
	usuario p;
	cout << "Ingrese los datos de los clientes de la EPE: " << endl;
	cout << "  - Ingrese número de usuario: "; cin >> p.nro;
	while (p.nro != 0){
		cout << "  - Ingrese tipo de usuario: "; cin >> p.tipo;
		cout << "  - Ingrese los Kws que consumió en el mes: "; cin >> p.kwcons;
		epe.push_back(p);
		cout << "  - Ingrese número de usuario: "; cin >> p.nro;
	}
	cout << endl;

	int a;
	cout << "Ingrese un nro de usuario para ver su consumo de Kw en el mes: "; cin >> a;
	pair<int,float>finish = funcion (epe,t,a);
	cout << "El usuario " << a << " consumió un total de " << finish.first << "Kw en el mes, con un gasto de $" << finish.second;
	return 0;
}

