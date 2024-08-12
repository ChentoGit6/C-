#include <iostream>
#include <vector>
using namespace std;
/*Leer las calificaciones de un grupo de 30 alumnos que asistieron a una evaluación
de programación. Mostrar las notas de los alumnos que se encuentren por encima
del promedio.
*/
int main() {
	float sumapromedio=0;
	vector<int>notas(10);
	for(int i=0;i<notas.size();i++) {
		cout << "Ingrese la nota "<<i+1<<":"<<endl;
		cin>>notas[i];
		sumapromedio = sumapromedio + notas[i];
	}
	float promedio = sumapromedio/notas.size();
	cout<<endl;
	cout << "El promedio es "<< promedio;
	cout<<endl<<endl;
	cout<<"Las notas que se encuentran por encima del promedio son:"<<endl;
	for(int i=0;i<notas.size();i++) { 
		if (notas[i]>promedio){
			cout<<notas[i]<<"  ";
		}
	}
	return 0;
}
