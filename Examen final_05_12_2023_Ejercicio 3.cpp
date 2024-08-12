#include <iostream>
using namespace std;
/*Un videojuego guarda en un vector de structs cierta información de los jugadores. Cada elemento del vector es un struct Jugador 
(string nombre, int cantidad partidas, int puntajie max); Cuando un jugador finaliza una partida, el programa dobe actualizar este 
vector. 
A) Escriba una función registrar Partida que reciba el vector, y el nombre de un jugador que acaba de finalizar. La función debe buscar 
al jugador por su nombre en el vector, incrementar en 1 su contador de partidas, y si el nuevo puntaje es mejor que su máximo anterior, 
actualizarlo también. Si el nombre del jugador no estaba en el vector, deberá agregario al final. La función debe retornar la posición 
del jugador en el vector y un bool que indique si se actualizó su mejor puntaje o no. B) Escribe un programa para probar la función que 
inicie con un vector vacio, permita ingresar los resultados de -N partidas
(Nes dato, y por cada una se ingresa nombre del jugador y puntaje obtenido), y al final muestre el vector resultante, y el nombre del mejor 
jugador de todos (el que mayor puntaje máximo logró, en caso de
empate, el que lo logró con una menor cantidad de partidas)
*/

struct jugador{
	string nombre;
	int cantidad_partidas;
	int puntaje_max;
};



int main() {
	
	return 0;
}

