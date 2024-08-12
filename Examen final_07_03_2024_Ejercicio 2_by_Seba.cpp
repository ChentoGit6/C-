#include <iostream>
#include <vector>
using namespace std;

vector<int> eliminarRepetidos(vector<int> arreglo) {	
	int indice = 0; // Este ínidice sirve para guardar la posicion de los elementos que no están repetidos
	
	for(size_t i=0;i<arreglo.size();++i) { // Acá el ++i es para que ya empiece en el siguiente elemento (para compararlo con el que tiene índice que es el 0)
		if (arreglo[i] != arreglo[indice]) {//Me fijo si el elemento siguiente a índice es distinto al de índice
			arreglo[++indice] = arreglo[i];//Si es así, incremento indice y guardo en esa posicion el elemento distinto que encontre
		}// en caso de que los elementos sigan siendo iguales la i se sigue moviendo y no hago nada, dejo el indice quieto hasta que encuentro otro distinto, 
		//Al final ponele que la lista pasa de {1, 1, 2, 2, 3, 4, 4, 5, 6, 6, 6, 7} a {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 6}, entonces ahí
	}
	arreglo.resize(indice + 1); // Actualizo el tamaño del arreglo a la nueva longitud eliminando todos los que quedaron despues de indice
	return arreglo;
}

vector<int> insertarEnOrden(vector<int> arreglo, int elemento) {
	//Si el arreglo esta vacío le inserto el primer elemnto y lo retorno
	if (arreglo.size() == 0){
		arreglo.push_back(elemento);
		return arreglo;
	}
	
	//Si no está vacío creo un índice para buscar donde inserar
	size_t indice = 0;
	while ((arreglo[indice] <= elemento) and (indice < arreglo.size())) {//Mientras no llego al final del arreglo o los elementos sean menores sigo 
		++indice;
	}
	//Cuando sale del while ya puedo insertar el elemento donde me indica el indice, para eso agrando el arreglo a un elemento mas
	arreglo.resize(arreglo.size()+1);
	
	// Muevo los elementos hacia la derecha para insertar el nuevo número
	for (size_t i = arreglo.size()-1; i > indice; --i) {
		arreglo[i] = arreglo[i - 1];
	}
	//Inserto
	arreglo[indice] = elemento;
	
	return arreglo;
}

int main() {
	vector<int> arreglo_con_repetidos;
	bool salir = false;
	int n;
	while(!salir){
		cout<<"Ingrese un numero para agregar al vector (-1 para terminar): ";
		cin>> n;
		if(n != -1){
		arreglo_con_repetidos = insertarEnOrden(arreglo_con_repetidos, n);
		}else{
			salir = true;
		}
	}
	vector<int> arreglo_sin_repetidos = eliminarRepetidos(arreglo_con_repetidos);
	for(size_t i=0;i<arreglo_sin_repetidos.size();i++) { 
		cout<<arreglo_sin_repetidos[i]<<"   ";
	}
	return 0;
}

