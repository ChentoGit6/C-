#include <iostream>
#include <vector>
using namespace std;
/*Un salón de videojuegos posee diferentes máquinas. Por cada máquina se conoce el nombre
del juego, el precio de cada partida, el mejor puntaje, y el nombre del jugador que obtuvo ese puntaje.
Cada cliente tiene una tarjeta, y cada tarjeta está asociada a un número de tarjeta, el nombre de un
cliente, un saldo (cantidad de dinero precargado para jugar), una cantidad de créditos que acumula al
jugar para luego canjear premios, y la fecha de la última vez que se usó. a) Defina un struct para guardar
los datos de una máquina, y otro para los datos de una tarjeta. Luego implemente las siguientes funciones:
b) comenzarJuego: que reciba un vector de máquinas, un vector de tarjetas, un nro de tarjeta, el nombre
de un juego y la fecha actual: la función debe descontar el precio de la partida de la tarjeta del cliente y
actualizar la fecha de último uso, solo si el cliente tiene suficiente dinero en la tarjeta. Debe retornar un
bool indicando si puede o no.
c) finalizarJuego: que reciba los dos vectores de datos, un nro de tarjeta, el nombre de un juego, el puntaje
obtenido, y la cantidad de créditos para canje que ganó en la partida: la función debe actualizar, si
corresponde, el mejor puntaje del juego y el nombre asociado, y sumar los créditos para canje en la
tarjeta.
d) recargarTarjeta: que reciba el vector de tarjetas, un nro de tarjeta, y un monto que debe sumar al dinero
disponible en esa tarjeta. La función debe retornar el nuevo monto disponible.
e) eliminarTarjetas: que reciba el vector de tarjetas y la fecha actual, y elimine del mismo todas las tarjetas
que no o se hayan utilizado en los últimos 2 años.
Nota: no debe implementar el programa cliente (main), solo las funciones.
*/

struct maquina{
	string nombre_juego;
	float precio_partida;
	float mejor_puntaje;
	string jugador_mp;
};
struct tarjeta{
	int numero_tarjeta;
	string cliente_tarjeta;
	float saldo;
	float credito;
	int fecha;
};
//b) comenzarJuego: que reciba un vector de máquinas, un vector de tarjetas, un nro de tarjeta, el nombre
//de un juego y la fecha actual: la función debe descontar el precio de la partida de la tarjeta del cliente y
//actualizar la fecha de último uso, solo si el cliente tiene suficiente dinero en la tarjeta. Debe retornar un
/*bool indicando si puede o no.*/
bool comenzarjuego(vector<maquina>m,vector<tarjeta>t,int numero_tarjeta,string nombre_juego,int fechaactual){
	float precio=0;
	for(size_t i=0;i<m.size();i++) { 
		if (m[i].nombre_juego==nombre_juego){
			precio = m[i].precio_partida;
		}
	}
	bool sepudo=false;
	for(size_t i=0;i<t.size();i++) { 
		if (t[i].numero_tarjeta==numero_tarjeta){
			if (t[i].saldo>precio){
				t[i].saldo = t[i].saldo - precio;
			    t[i].fecha=fechaactual;
				sepudo = true;
			}
		}
	}
	return sepudo;
}
//c) finalizarJuego: que reciba los dos vectores de datos, un nro de tarjeta, el nombre de un juego, el puntaje
//obtenido, y la cantidad de créditos para canje que ganó en la partida: la función debe actualizar, si
//corresponde, el mejor puntaje del juego y el nombre asociado, y sumar los créditos para canje en la tarjeta.
void finalizarjuego (vector<maquina>m,vector<tarjeta>t,string nombre_juego,float puntajeobtenido,float credito,int numero_tarjeta){
	string jugador;
	for(size_t i=0;i<t.size();i++) { 
		if (t[i].numero_tarjeta == numero_tarjeta){
			t[i].credito + credito;
			jugador = t[i].cliente_tarjeta;
		}
	}
	for(size_t i=0;i<m.size();i++) { 
		if (m[i].nombre_juego==nombre_juego){
			if(m[i].mejor_puntaje<puntajeobtenido){
				m[i].mejor_puntaje=puntajeobtenido;
				t[i].cliente_tarjeta=jugador;
			}
		}
	}
}
//d) recargarTarjeta: que reciba el vector de tarjetas, un nro de tarjeta, y un monto que debe sumar al dinero
//disponible en esa tarjeta. La función debe retornar el nuevo monto disponible.
float recargartarjeta (vector<tarjeta>t,int numero_tarjeta,float monto){
	float montodisponible=0;
	for(size_t i=0;i<t.size();i++) { 
		if(t[i].numero_tarjeta==numero_tarjeta){
			t[i].saldo += monto;
			montodisponible = t[i].saldo;
		}
	}
	return montodisponible;
}
//e) eliminarTarjetas: que reciba el vector de tarjetas y la fecha actual, y elimine del mismo todas las tarjetas
//que no o se hayan utilizado en los últimos 2 años.
void eliminartarjetas (vector<tarjeta>t,int fechaactual){
	for(size_t i=0;i<t.size();i++) { 
		if (fechaactual-t[i].fecha>=2){
			/*t[i].erase() para eliminar directamente la tarjeta*/
			for(size_t j=i;j<t.size()-1;j++) {
				t[j]=t[j+1];
				
			}	
			t.resize(t.size()-1);
		}
	}
}
int main() {
	
	return 0;
}

