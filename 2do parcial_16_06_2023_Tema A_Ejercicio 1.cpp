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
			break;
			return i;
			
		}else if(v[i] != s){
			break;
			return -1;
			
		}
	}
}

int main() {
	
	return 0;
}

