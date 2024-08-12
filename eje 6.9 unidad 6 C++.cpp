#include <iostream>
using namespace std;
/*Un usuario desea conocer cu�nto le cuesta el combustible de cada viaje que
realiza en su auto. Para ello anota el kilometraje que marca el od�metro justo antes
de iniciar el viaje, y toma nota nuevamente justo al llegar a destino. Conoce
adem�s el consumo de nafta del veh�culo en ruta (es decir, cuantos litros gasta en
promedio por cada kil�metro recorrido), y el precio del litro de nafta. Escriba un
algoritmo para calcular el costo de un viaje. �C�mo modificar�a el algoritmo para
considerar un % de descuento para los d�as en que hay promociones para clientes
habituales en la estaci�n de servicio?
*/
int main() {
	cout << "Indique el kilometraje que marca el od�metro antes de iniciar el viaje: ";
	float kilometrajeinicio;
	cin >> kilometrajeinicio;
	cout << "Indique el kilometraje que marca el od�metro al llegar a destino: ";
	float kilometrajefin;
	cin >> kilometrajefin;
	cout << "Indique el consumo de nafta del veh�culo(litros que gasta en promedio por cada km recorrido): ";
	float consumonafta;
	cin >> consumonafta;
	cout << "Indique el preco del litro de nafta: ";
	float naftaprecio;
	cin >> naftaprecio;
	
	float costodeviaje = ((kilometrajefin - kilometrajeinicio)/consumonafta)*naftaprecio;
	cout << "Su costo total de viaje es "<<costodeviaje<<"$"<<endl;
	cout << "�Usted es cliente habitual de la estaci�n de servicio? ";
	string respuesta;
	cin >> respuesta;
	if (respuesta=="si"){
		cout << "Posee descuento del 20% para los d�as Martes, Viernes y Domingo"<<endl;
		cout << "�Qu� dia es hoy? ";
		string dia;
		cin >> dia;
		if (dia == "martes"|| dia=="viernes"||dia=="domingo"){
			cout << "Tiene descuento del 20%"<<", le queda un costo de "<<costodeviaje*0.8<<"$"<<endl;
		} else{
			cout << "Vuelve otro d�a"<<endl;
		}
		
	}else {
		cout << "No posee descuento, su costo final es "<<costodeviaje<<"$"<<endl;
	}
	return 0;
}

