#include <iostream>
#include <vector>
using namespace std;
/*) Escriba una función buscar que reciba un vector de strings v, un string s, y una posición p. La función
debe buscar el valor s en el vector v, solo desde la posición p en adelante, y retornar la primera posición donde lo
encuentre, o -1 en caso de no encontrarlo. b) Utilizando la función buscar, escriba una función reemplazar que
reciba un vector de strings, y dos strings s1 y s2. La función debe reemplazar todas las ocurrencias de s1 en el
vector por s2; y retornar la cantidad de reemplazos realizados.
*/

int buscar (vector<string>v, string s, int p){
	for(size_t i=p;i<v.size();i++) { 
		if (v[i] == s){
			return i;
			
		}
	}
	return -1;
}
	
int reemplazar (vector<string>f, string s1, string s2){
	int tochi;
	int cont = 0;
	for(size_t i=0;i<f.size();i++) { 
		tochi = buscar (f,s1,i);
		if (tochi != -1){
			f[tochi] = s2;
			cont ++;
		} else {
			continue;
		}
	}
	return cont;
}

int main() {
	int n;
	cout << "Ingrese el tamaño del vector: "; cin >> n;
	vector<string>f(n);
	cout << "Ingrese los strings del vector" << endl;
	for(size_t i=0;i<f.size();i++) { 
		cin >> f[i];
	}
	string h, c;
	for(size_t i=0;i<f.size();i++) { 
		cout << f[i] << "  ";
	}
	cout << endl;
	cout << "Ingrese strings para buscar y string para reemplazar:" << endl;
	cin >> h >> c;
	int x = reemplazar (f,h,c);
	cout << "Se reemplazo " << h << " por " << c << " " << x << " veces";
	return 0;
}

