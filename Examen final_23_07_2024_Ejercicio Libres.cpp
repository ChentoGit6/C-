#include <iostream>
#include <vector>
using namespace std;
/*Codifique una función que reciba un vector v de enteros que puede tener valores repetidos y retorne un nuevo vector x de structs, donde cada 
struct/elemento tenga dos datos: un valor del vector v y la cantidad de veces que se repite (ese valor en v). Este nuevo vector x debe estar ordenado 
según el valor. Por ejemplo, si el vector inicial es v(80, 20, 80, 30, 40,30, 80), el vector resultante será x=(20:1), (30;2), (40,1), (80;3)).
Ayuda: utilice una función auxiliar para buscar/insertar valores en x, que reciba un valor de v, lo busque en x (busque un struct que tenga ese 
valor como primer dato), y si no lo encuentra lo inserte donde corresponda para mantener el orden.
*/

struct datos {
	int valor, valor_rep = 1;
};


int main() {
	vector<int>e = {80, 20, 80, 30, 40,30, 80};
	vector<datos>nuevoe = x(e);
	for(size_t i=0;i<nuevoe.size();i++) { 
		cout<<nuevoe[i].valor << ";" << nuevoe[i].valor_rep<<endl;
	}
	return 0;
}

