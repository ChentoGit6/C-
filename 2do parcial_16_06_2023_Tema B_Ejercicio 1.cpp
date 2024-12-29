/*Ej1 a) Defina un struct equipoF1{..} para guardar los datos de un equipo de Fórmula 1 que tiene 4
miembros: nombre del equipo, nombre piloto titular 1, nombre piloto titular 2, nombre piloto de reserva. b) Escriba
una función sustituir_piloto(..) que reciba un vector de tipo equipoF1 y el nombre de un piloto titular de uno de los
equipos. La función debe buscar en el vector al piloto por su nombre e intercambiarlo (nombre) por el piloto de
reserva de ese mismo equipo. La función debe retornar el nombre del piloto reserva que lo sustituye, o la cadena "no
encontrado" en caso de que no encuentre al piloto a reemplazar dentro de la lista. c) Escriba un programa cliente
para probar la función: que permita cargar una lista de equipos, sustituir un piloto que elija el usuario, y mostrar la
nueva lista (o un mensaje de error si la sustitución no se realiza).
*/

#include <iostream>
#include <vector>
using namespace std;

struct equipoF1 {
	string nomequipo;
	string nompt1;
	string nompt2;
	string nompr;
};

string sustituir_piloto (vector<equipoF1>&v, string &nompt){
	string aux;
	for(size_t i=0;i<v.size();i++) { 
		if (v[i].nompt1 == nompt){
			aux = v[i].nompt1;
			v[i].nompt1 = v[i].nompr;
			v[i].nompr = aux;
			return v[i].nompr;
		} else if (v[i].nompt2 == nompt){
			aux = v[i].nompt2;
			v[i].nompt2 = v[i].nompr;
			v[i].nompr = aux;
			return v[i].nompr;
		}
	} 
	return "no encontrado";
}

int main() {
	int n;
	cout << "Ingrese la cantidad de equipos: "; cin >> n;
	cin.ignore();
	vector<equipoF1>v(n);
	for(size_t i=0;i<v.size();i++) { 
		cout << "Equipo " << i + 1 << ":" << endl;
		cout << "Nombre del equipo: ";
		getline(cin, v[i].nomequipo);
		cout << "Nombre del piloto titular 1: ";
		getline(cin, v[i].nompt1);
		cout << "Nombre del piloto titular 2: ";
		getline(cin, v[i].nompt2);
		cout << "Nombre del piloto reserva: ";
		getline(cin, v[i].nompr);
	}
	cout << endl;
	string s;
	cout << "Ingrese nombre del piloto a sustituir: ";
	cin.ignore();
	getline(cin, s);
	string pilotr = sustituir_piloto (v,s);
	if (pilotr == "no encontrado") {
		cout << "El piloto no fue encontrado en la lista de equipos" << endl;
	} else {
		cout << "El piloto " << pilotr << " ha sustituido a " << s << endl;
	}
	cout << "Lista actualizada de equipos:" << endl;
	for (size_t i=0;i<v.size();i++) {
		cout << "Equipo: " << v[i].nomequipo << "\n"
			<< "  Titular 1: " << v[i].nompt1 << "\n"
			<< "  Titular 2: " << v[i].nompt2 << "\n"
			<< "  Reserva: " << v[i].nompr << "\n";
	}
	return 0;
}
