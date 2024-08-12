#include <iostream>
#include <matrix>
#include <vector>
#include <iomanip>
using namespace std;
/*Implemente una funci�n que inserte un vector como nueva fila en una matriz en una posici�n dada. Se debe 
insertar, no reemplazar. Es decir: por par�metro llega una matriz, una posici�n y un vector. Ejemplo, matriz de 
4x5, vector de 5 elementos enteros, la matriz restante quedaria de 5x5. No debe usar una matriz auxiliar. La 
funci�n debe retornar un valor l�gico que ser� verdadero cuando efectivamente se inserte la fila.
Si el vector no tiene el tama�o adecuado o el �ndice de fila es menor a 0, la inserci�n no puede realizarse. Si 
el indice de fila es mayor al tama�o de la matriz, la funci�n debe redimensionarla agregando filas de Os hasta el
tama�o necesario (por ej,en una matriz de 3x3, si se quiere insertar el vector en una 6ta fila, hay completar con 
2 filas de Os antes). Nota: no se pide el programa cliente, solo la funci�n.
*/

bool funcion (matrix<int>&m, vector<int>v, int pos){
	if (v.size() != m.size(0) || pos < 0){
		return false;
	}
	if (pos > m.size(0)){
		int contador = m.size(0);
		while (contador < pos){
			m.resize(m.size(0)+1,m.size(1));
			contador ++;
		}
		for(size_t i=m.size(0)-1;i>pos-1;i--) { 
			for(size_t j=0;j<m.size(1);j++) { 
				m[i][j] = m[i-1][j];
			}
		}	
		for(size_t j=0;j<m.size(1);j++) {  
			m[pos-1][j] = v[j];
		}
		return true;
	}
	if (pos <= m.size(0)){
		m.resize(m.size(0)+1,m.size(1));
		for(size_t i=m.size(0)-1;i>pos-1;i--) { 
			for(size_t j=0;j<m.size(1);j++) { 
				m[i][j] = m[i-1][j];
			}
		}	
		for(size_t j=0;j<m.size(1);j++) {  
			m[pos-1][j] = v[j];
		}
		
		return true;
	}
	return false;
}

int main() {
	int n,valor1,valor2;
	cout << "Ingrese la dimension de la matrix y el vector(que sean iguales): ";
	cin >> n;
	cout << "Ingrese con que valores quiere que se inicializen: "<< endl;
	cout << "   - Matriz: "; cin >> valor1;
	cout << "   - Vector: "; cin >> valor2;
	matrix<int>m(n,n,valor1);
	vector<int>v(n,valor2);
	int pos;
	cout << " Ingrese la posici�n en la que quiere insertar el vector en la matriz: ";
	cin >> pos;
	bool rta = funcion(m,v,pos);
	
	for(size_t i=0;i<m.size(0);i++) { 
		for(size_t j=0;j<m.size(1);j++) { 
			cout << setw(5) << m[i][j] << "   ";
		}
		cout << endl;
	}
	return 0;
}

