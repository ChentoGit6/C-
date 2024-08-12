#include <iostream>
using namespace std;
/*Un usuario desea conocer cuánto le cuesta el combustible de cada viaje que
realiza en su auto. Para ello anota el kilometraje que marca el odómetro justo antes
de iniciar el viaje, y toma nota nuevamente justo al llegar a destino. Conoce
además el consumo de nafta del vehículo en ruta (es decir, cuantos litros gasta en
promedio por cada kilómetro recorrido), y el precio del litro de nafta. Escriba un
algoritmo para calcular el costo de un viaje. ¿Cómo modificaría el algoritmo para
considerar un % de descuento para los días en que hay promociones para clientes
habituales en la estación de servicio?
*/
int main() {
	cout << "Indique el kilometraje que marca el odómetro antes de iniciar el viaje: ";
	float kilometrajeinicio;
	cin >> kilometrajeinicio;
	cout << "Indique el kilometraje que marca el odómetro al llegar a destino: ";
	float kilometrajefin;
	cin >> kilometrajefin;
	cout << "Indique el consumo de nafta del vehículo(litros que gasta en promedio por cada km recorrido): ";
	float consumonafta;
	cin >> consumonafta;
	cout << "Indique el preco del litro de nafta: ";
	float naftaprecio;
	cin >> naftaprecio;
	
	float costodeviaje = ((kilometrajefin - kilometrajeinicio)/consumonafta)*naftaprecio;
	cout << "Su costo total de viaje es "<<costodeviaje<<"$"<<endl;
	cout << "¿Usted es cliente habitual de la estación de servicio? ";
	string respuesta;
	cin >> respuesta;
	if (respuesta=="si"){
		cout << "Posee descuento del 20% para los días Martes, Viernes y Domingo"<<endl;
		cout << "¿Qué dia es hoy? ";
		string dia;
		cin >> dia;
		if (dia == "martes"|| dia=="viernes"||dia=="domingo"){
			cout << "Tiene descuento del 20%"<<", le queda un costo de "<<costodeviaje*0.8<<"$"<<endl;
		} else{
			cout << "Vuelve otro día"<<endl;
		}
		
	}else {
		cout << "No posee descuento, su costo final es "<<costodeviaje<<"$"<<endl;
	}
	return 0;
}

