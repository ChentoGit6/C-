#include <iostream>
using namespace std;
/*Un videojuego guarda en un vector de structs cierta informaci�n de los jugadores. Cada elemento del vector es un struct Jugador 
(string nombre, int cantidad partidas, int puntajie max); Cuando un jugador finaliza una partida, el programa dobe actualizar este 
vector. 
A) Escriba una funci�n registrar Partida que reciba el vector, y el nombre de un jugador que acaba de finalizar. La funci�n debe buscar 
al jugador por su nombre en el vector, incrementar en 1 su contador de partidas, y si el nuevo puntaje es mejor que su m�ximo anterior, 
actualizarlo tambi�n. Si el nombre del jugador no estaba en el vector, deber� agregario al final. La funci�n debe retornar la posici�n 
del jugador en el vector y un bool que indique si se actualiz� su mejor puntaje o no. B) Escribe un programa para probar la funci�n que 
inicie con un vector vacio, permita ingresar los resultados de -N partidas
(Nes dato, y por cada una se ingresa nombre del jugador y puntaje obtenido), y al final muestre el vector resultante, y el nombre del mejor 
jugador de todos (el que mayor puntaje m�ximo logr�, en caso de
empate, el que lo logr� con una menor cantidad de partidas)
*/

struct jugador{
	string nombre;
	int cantidad_partidas;
	int puntaje_max;
};



int main() {
	
	return 0;
}

