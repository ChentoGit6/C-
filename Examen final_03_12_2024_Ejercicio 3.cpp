/*Ej 3 (30 pts) Un sistema de gestión de una biblioteca utiliza un vector<Prestamo> para la información de préstamos en 
curso (de libros que no han sido devueltos) y otro para el historial (los que ya han sido devueltos). Siendo struct Prestamo
{ int cod_socio, cod_libro; Fecha fecha_prestamo, fecha_devolucion } y struct Fecha { int dia, mes, ano }. En el vector de
préstamos en curso fecha_devolucion indica cuándo el socio debería devolver el libro; en el historial indica cuándo efectivamente 
lo devolvió. Escriba una función para registrar la devolución de un libro: la función debe recibir ambos vectores, el código del 
libro y la fecha actual. De buscar el préstamo correspondiente a ese libro en el vector de préstamos en curso, eliminarlo de allí 
y agregar esos datos (modificando la fecha de devolución con la fecha actual) en el vector del historial. La función debe además 
retornar true si la devolución se realizó a término (si la fecha de devolución original no es previa a la fecha actual), o false 
en caso contrario.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Fecha {
	int dia, mes, anio;
};

struct Prestamo {
	int cod_socio, cod_libro;
	Fecha fecha_prestamo, fecha_devolucion;
};
void eliminar (vector<Prestamo>&curso, int indice){
	for(size_t i=indice;i<curso.size()-1;i++) { 
		curso[i] = curso[i+1];
	}
	curso.resize(curso.size()-1);
}

bool biblioteca (vector<Prestamo>curso, vector<Prestamo>historial, int cod_libro, Fecha fecha_actual){
	int indice;
	Prestamo a;
	for(size_t i=0;i<curso.size();i++) { 
		if (curso[i].cod_libro == cod_libro){
			indice = i;
			a = curso[i];
			eliminar (curso,indice);
			break;
		}
	}
	Fecha f = a.fecha_devolucion;
	
	a.fecha_devolucion = fecha_actual;
	
	historial.push_back(a);
	
	if (f.anio > fecha_actual.anio){
		return false;
	} else if (f.anio == fecha_actual.anio){
		if (f.mes > fecha_actual.mes){
			return false;
		} else if (f.mes == fecha_actual.mes){
			if (f.dia > fecha_actual.dia){
				return false;
			}
		}
	}
	return true;
}

int main() {
	
	return 0;
}

