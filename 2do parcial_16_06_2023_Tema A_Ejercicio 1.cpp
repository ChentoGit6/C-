#include <iostream>
#include <vector>
using namespace std;
/*) Escriba una funci�n buscar que reciba un vector de strings v, un string s, y una posici�n p. La funci�n
debe buscar el valor s en el vector v, solo desde la posici�n p en adelante, y retornar la primera posici�n donde lo
encuentre, o -1 en caso de no encontrarlo. b) Utilizando la funci�n buscar, escriba una funci�n reemplazar que
reciba un vector de strings, y dos strings s1 y s2. La funci�n debe reemplazar todas las ocurrencias de s1 en el
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

