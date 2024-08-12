#include <iostream>
using namespace std;
/*Dise�e una funci�n C++ que se la invoque de la siguiente forma: e = edad(f_nac,f_hoy);
siendo f_nac y f_hoy de tipo Fecha: un struct con 3 miembros enteros: dia, mes, anio. La funci�n debe
devolver la edad de una persona que naci� en la fecha f_nac, siendo f_hoy la fecha de hoy.  
*/

struct fecha{
	int dia;
	int mes;
	int anio;	
};

fecha edad(fecha f_nac, fecha f_hoy){
	
	fecha edad;
	edad.anio = f_hoy.anio-f_nac.anio;
	edad.mes = f_hoy.mes-f_nac.mes;
	edad.dia = f_hoy.dia-f_nac.dia;
	
	return edad;
}
	
	int main() {
		
		fecha f_nac;
		fecha f_hoy;
		cout<< "Ingresa tu fecha de nacimiento: "<<endl;
		cout<<endl;
		cout<<"D�a: ";cin>>f_nac.dia;
		cout<<"Mes: ";cin>>f_nac.mes;
		cout<<"A�o: ";cin>>f_nac.anio;
		cout<<endl;
		cout<< "Ingresa la fecha actual: "<<endl;
		cout<<"D�a: ";cin>>f_hoy.dia;
		cout<<"Mes: ";cin>>f_hoy.mes;
		cout<<"A�o: ";cin>>f_hoy.anio;
		cout<<endl;
		fecha e = edad(f_nac,f_hoy);
		cout << "Usted tiene: "<<endl;
		cout << e.anio<<" a�o/s, "<<e.mes<<" mes/es, "<<e.dia<<" dia/s";
		
		return 0;
	}

