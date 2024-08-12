#include <iostream>
#include <vector>
using namespace std;

/*Leer los nombres y calificaciones de un grupo de alumnos que asistieron a una
evaluación de programación. Los datos finalizan con la calificación 0. Generar un
vector con los nombres de los alumnos aprobados (calificación>=6) y otro con los
nombres de los no aprobados. Mostrar luego ambos vectores.
*/
struct alumno{
	int nota;
	string nombre;
};

int main() {
	vector<int>nota;
	vector<string>nombre;
	int calificacion=1;
	string nom;
	while(calificacion!=0){
		cin>>calificacion;
		cin>>nom;
		if (calificacion!=0){
			nota.push_back(calificacion);
			nombre.push_back(nom);
		}
	}
	vector<alumno>aprobados;
	vector<alumno>desaprobados;
	alumno alumnoaux;
	
	for(int i=0;i<nota.size();i++) { 
		alumnoaux.nombre=nombre[i];
		alumnoaux.nota=nota[i];
		if(nota[i]>=6){			
			aprobados.push_back(alumnoaux);
		}else{
			desaprobados.push_back(alumnoaux);;
		}
	}
	for(int i=0;i<aprobados.size();i++) { 
		cout<<aprobados[i].nombre<<" nota: "<<aprobados[i].nota<<endl;
	}
	for(int i=0;i<desaprobados.size();i++) { 
		cout<<desaprobados[i].nombre<<" nota: "<<desaprobados[i].nota<<endl;
	}
	
//	cout<<aprobados;
//	cout<<endl<<endl;
//	cout<<desaprobados;
	return 0;
}

