#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <string> vnombres;
	vector <int> vnotas;
	vector <string> vaprobados;
	vector <string> vdesaprobados;
	cout << "Ingresar el nombre de la persona para cargarle la nota" << endl;
	string nombre;
	cin >> nombre;
	cout << "Ingrese la nota de "<<nombre<<endl;
	int nota;
	cin >> nota;
	while (nota > 0){
		vnotas.push_back(nota);
		vnombres.push_back(nombre);
		cout << "Ingresar el nombre de la persona para cargarle la nota" << endl;
		cin >> nombre;
		cout << "Ingrese la nota de "<<nombre<<endl;
		cin >> nota;
	}
	for(int i=0;i<vnotas.size();i++) { 
		if (vnotas [i] >= 6){
			vaprobados.push_back(vnombres[i]);
		}
		else
			vdesaprobados.push_back(vnombres[i]);
		
	}
	cout << "Los desaprobados son: " <<endl;
	for(int i=0;i<vdesaprobados.size();i++) { 
		cout << vdesaprobados[i] << "  ";
	}
	cout << endl;
	cout << "Los aprobados son: " <<endl;
	for(int i=0;i<vaprobados.size();i++) { 
		cout << vaprobados[i] << "  ";
	}
	return 0;
}

