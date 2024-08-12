#include <iostream>
#include <vector>
using namespace std;

struct Fecha {
	int dia, mes, anio;
};

int edad(Fecha fnac, Fecha fhoy) {
	int n1 = fnac.anio*10000 + fnac.mes*100 + fnac.dia;
	int n2 = fhoy.anio*10000 + fhoy.mes*100 + fhoy.dia;
	return (n2-n1)/10000;
}

struct Socio {
	string ape, nom;
	int dni;
	string cat;
	Fecha fnac;
};

void actualizar(vector<Socio> &v, Fecha fhoy) {
	for (size_t i=0; i<v.size(); ++i) {
		int e = edad(v[i].fnac,fhoy);
		if (e<=12) v[i].cat = "infantiles";
		else {
			if (e<=18) v[i].cat = "juveniles";
			else       v[i].cat = "mayores";
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<Socio> v(n);
	for (size_t i=0; i<v.size(); ++i) {
		cin.ignore();
		getline(cin,v[i].nom);
		getline(cin,v[i].ape);
		cin >> v[i].dni;
		cin >> v[i].cat;
		cin >> v[i].fnac.dia;
		cin >> v[i].fnac.mes;
		cin >> v[i].fnac.anio;
	}
	
	Fecha fhoy;
	cin >> fhoy.dia >> fhoy.mes >> fhoy.anio;
	actualizar(v,fhoy);
	
	float inf, juv, may;
	cin >> inf >> juv >> may;
	float rec = 0;
	for (size_t i=0; i<v.size(); ++i) {
		if (v[i].cat=="juveniles") {
			rec += juv;
		} else {
			if (v[i].cat=="mayores")
				rec += may;
			else
				rec += inf;                     
		}
	}
	cout << rec;
	return 0;
}

