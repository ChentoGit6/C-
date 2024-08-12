#include <iostream>
#include <vector>
using namespace std;
/*Diseñe una función C++ que se la invoque de la siguiente forma: e = edad(f_nac,f_hoy);
siendo f_nac y f_hoy de tipo Fecha: un struct con 3 miembros enteros: dia, mes, anio. La función debe
devolver la edad de una persona que nació en la fecha f_nac, siendo f_hoy la fecha de hoy.
Considere club deportivo barrial que tiene N socios, y cada socio paga una cuota de acuerdo a su categoría:
infantiles (hasta 12 años inclusive), juveniles (hasta 18 años inclusive) y mayores (más de 18 años).
Escriba un programa C++ que organice en un único vector los datos de cada asociado: apellido, nombres,
dni, categoría, fecha de nacimiento (de tipo Fecha). Debe leer primero los 3 valores de la cuota (de cada
categoría), y a continuación los datos de los N socios. c) El programa debe actualizar el vector de socios
considerando la fecha de hoy a través de una función actualizar(..), pues varios socios pueden haber
cambiado de categoría al cambiar su edad; y luego d) calcular la recaudación mensual del club si todos
los socios pagaran su cuota al día de hoy.
*/

struct fecha{
int dia;
int mes;
int anio;	
};

struct socio {
	string apellido;
	string nombre;
	int dni;
	string categoria;
	fecha f_nac;
};
int edad(fecha f_nac, fecha f_hoy){
	
	int n1 = f_nac.anio*10000 + f_nac.mes*100 + f_nac.dia;
	int n2 = f_hoy.anio*10000 + f_hoy.mes*100 + f_hoy.dia;
	return (n2-n1)/10000;
}
void actualizar(vector<socio>&club, fecha fecha_hoy){
	for(size_t i=0;i<club.size();i++) { 
		int e = edad(club[i].f_nac, fecha_hoy);
		if (e <= 12) club[i].categoria = "infantil";
	    else {
			if (e <= 18) club[i].categoria = "juvenil";
		    else club[i].categoria = "mayor";
		}
	}
}
int main() {
	float cuotainfantil,cuotajuvenil,cuotamayores;
	cout << "Ingrese el valor de la cuota infantil: ";cin>>cuotainfantil;
	cout << "Ingrese el valor de la cuota juveníl: ";cin>>cuotajuvenil;
	cout << "Ingrese el valor de la cuota mayores: ";cin>>cuotamayores;
	cout<<endl;
	cout << "Ingrese el número de socios: ";
	int N;
	cin>>N;
	vector<socio>club(N);
	
	for(size_t i=0;i<club.size();i++) { 
	cout<<"Ingrese el apellido del socio "<<i+1<<": ";cin >> club[i].apellido;	
	cout<<"Ingrese el nombre del socio "<<i+1<<": ";cin >> club[i].nombre;
	cout<<"Ingrese el dni del socio "<<i+1<<": ";cin >> club[i].dni;
	cout<<"Ingrese la categoría del socio "<<i+1<<": ";cin >> club[i].categoria;
	cout<<"Ingrese la fecha de nacimiento del socio "<<i+1<<": ";cin >> club[i].f_nac.dia;cout<<"/";cin >> club[i].f_nac.mes;cout<<"/";cin >> club[i].f_nac.anio;
	}
	fecha fecha_hoy;
	cout<<"Ingrese la fecha de hoy"<<endl;
	cout<<"Día: ";cin>>fecha_hoy.dia;
	cout<<"Mes: ";cin>>fecha_hoy.mes;
	cout<<"Año: ";cin>>fecha_hoy.anio;
	actualizar(club,fecha_hoy);
	
	float recaudacion = 0;
	for(size_t i=0;i<club.size();i++) { 
		if (club[i].categoria=="infantil") recaudacion += cuotainfantil;
		else{
			if (club[i].categoria=="juvenil") recaudacion += cuotajuvenil;
			else recaudacion += cuotamayores;
		}
	}
	cout << "La recaudacion total del club es : "<<recaudacion<<"$";
	return 0;
}

