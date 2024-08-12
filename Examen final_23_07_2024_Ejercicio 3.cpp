#include <iostream>
#include <vector>
using namespace std;
/* Considere el struct ficha (int DNI, float altura:) que define como miembros el DNI y la altura de un grupo de personas. Escriba una función C++ 
que reciba como parámetros un vector A de tipo ficha ya ordenado en forma decreciente por altura. En el grupo organizado en A hay varias personas 
con la misma altura. Acomode los elementos del vector de modo que si hay personas de igual altura se ubique antes en el vector la persona de menor 
edad (número de DNI mayor). Se sabe que en el grupo no hay más de 3 personas con igual altura. No debe usar algoritmos ni métodos de la STL.
*/

struct ficha {
int DNI;
float altura;
};

void funcion (vector<ficha>&A){
	ficha siguiente, actual;
	for(size_t j=0;j<A.size()-1;j++) { 
		for(size_t j=0;j<A.size()-1;j++) { 
			actual = A[j];
			siguiente = A[j+1];
			if (actual.altura == siguiente.altura){
				if (actual.DNI < siguiente.DNI){
					A[j] = siguiente;
					A[j+1] = actual;
				}
			}
		}
	}
}

int main() {
	vector<ficha>v(5);
	for(size_t i=0;i<v.size();i++) { 
		cin >> v[i].DNI >>v[i].altura;
	}
	funcion(v);
	
	for(size_t i=0;i<v.size();i++) { 
		cout << v[i].DNI <<", "<<v[i].altura<<endl;
	}
	return 0;
}

