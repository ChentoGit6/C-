#include <iostream>
#include <matrix>
#include <vector>
#include <iomanip>
using namespace std;
struct num {
	int par = 0;
	int impar = 0;
};

pair<num,float> f2 (matrix<int>m, int fila){
	int im = 0, par = 0;
	num p;
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			if (m[i][j] % 2 == 0){
				par ++;
				p.par = par;
			} else {
				im ++;
				p.impar = im;
			}
		}
	}
	int suma; float prom;
	for(size_t j=0;j<m.size(1);j++) { 
		suma += m[fila][j];
	}
	prom = (suma / m.size(1)) * 100;
	pair<num,float>f;
	f.first = p;
	f.second = prom;
	return f;
}

matrix<int> f1 (matrix<int>m){
	vector<int>v;
	matrix<int>f(m.size(0), m.size(1));
	int valor;
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			if(m[i][j] % 2 == 0){
				valor = m[i][j];
				v.push_back(valor);
			}
		}
	}
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			if(m[i][j] % 2 != 0){
				valor = m[i][j];
				v.push_back(valor);
			}
		}
	}
	int contador = 0;
	for(size_t i=0;i<f.size(0);i++) { 
		for(size_t j=0;j<f.size(1);j++) { 
			f[i][j] = v[contador];
			contador++;
		}
	}
	return f;
}

int main() {
	cout << "Ingrese el tamaño con el que se va a inicializar la matriz: " << endl;
	int f, c;
	cout << "  - Filas: "; cin >> f;
	cout << "  - Columnas: "; cin >> c;
	cout << endl;
	matrix<int>m(f,c);
	cout << "Rellene la matriz con valores enteros aleatorios" << endl;
	cout << "El programa pondrá los valores pares primeros y luego los impares" << endl;
	cout << endl;
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			cout << "  * F" << i+1 <<" - "<<"C"<< j+1 <<": ";cin >> m[i][j];
		}
	}
	cout << endl;
	cout << " ***Matriz inicial***" << endl;
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			cout << setw(5) << m[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	m = f1(m);
	cout << " ***Matriz final***" << endl;
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			cout << setw(5) << m[i][j] << "  ";
		}
		cout << endl;
	}
	int fila;
	cin >> fila;
	cout << endl;
	pair<num,float>p = f2(m,fila);
	cout << p.first.par <<"  "<< p.first.impar << "  "<< p.second;
	return 0;
}

