/*Ejercicio 1 Escriba un programa en C++ que simule un sistema de control de acceso por contraseña de
la siguiente manera: a) En una primer etapa debe permitir cargar los datos de los usuarios válidos (pares de
datos: nombre y contraseña). No se conoce la cantidad de usuarios válidos y los datos terminan con el usuario
“ZZZ”. En esta carga inicial, debe verificar mediante un función validar_contraseña que la contraseña no sea
"1234", "asdf", "pass" ni la cadena vacía; mostrando un mensaje de error y solicitando el reingreso de la misma
en estos casos. (nota: proponga usted el prototipo de la función e impleméntela). b) Luego, simular el verdadero
intento de acceso al sistema. El programa debe mostrar el mensaje "Por favor, identifíquese:" y solicitar nombre
y contraseña. Si se ingresa un par nombre+contraseña existente (que coincida con los cargados en el apartado a)
se debe mostrar el mensaje "Bienvenido al sistema sr X" (reemplazando X por el nombre del usuario); sino,
luego de 5 intentos fallidos debe mostrar el mensaje "Fuera bicho!".
*/

#include <iostream>
#include <vector>
using namespace std;

struct user {
	string name;
	string password;
};

string valid_password (string f){
	if (f == "1234" || f == "asdf" || f == "pass" || f == ""){
		return "Error!@#1|3, try again ";
	}
	return "oo";
}

bool buscar (string n, string p, vector<user>v){
	for(size_t i=0;i<v.size();i++) { 
		if (n == v[i].name){
			if (p == v[i].password){
				return true;
			}
		}
	}
	return false;
}

int main() {
	vector<user>v;
	user a;
	cout << "Name: "; cin >> a.name;
	while (a.name != "ZZZ"){
		cout << "Password: "; cin >> a.password;
		string s = valid_password (a.password);
		while (a.password=="1234"||a.password=="asdf"||a.password=="pass"||a.password==""){
			if (s == "Error!@#1|3, try again "){
				cout << s;
				cout << "Password: "; cin >> a.password;
			}
		}
		v.push_back(a);
		cout << "Name: "; cin >> a.name;
	}
	string n, p;
	int cont = 0;
	cout << "Please, identificacion: "; cin >> n;
	cout << "Password: "; cin >> p;
	bool b = buscar (n,p,v);
	while (b == true || cont < 5){
		if (b == true){
			cout << "Bienvenido sr. " << n;
			break;
		} else {
			cout << "Incorrect" << endl;
			cont ++;
		}
		cout << "Please, identificacion: "; cin >> n;
		cout << "Password: "; cin >> p;
		b = buscar (n,p,v);
	}
	if (cont == 5){
		cout << "Get out insect!";
	}
	return 0;
}

