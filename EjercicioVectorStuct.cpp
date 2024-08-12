#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;
/**
  Codificar una función que rertorne un vector con las provincias que encuentre
  en el vector 

  Codificar una función que retorne una lista de personas de una provincia que
  ingresa como parámetro

  Usar las dos funciones para mostrar en pantalla las personas por provincia
  PROVINCIA 1
      NOMBRE1   -  LOCALIDAD
      NOMBRE2   -  LOCALIDAD
	  .........................
  
  PROVINCIA 2 
      NOMBRE1   -  LOCALIDAD
      NOMBRE2   -  LOCALIDAD
      .........................
**/
struct persona {
	int dni;
	string nombre;
	string provincia;
	string localidad;
	string sexo; /// F o M
};

void CargarDatos(vector<persona>&personas);

int main() {
	/// un vector vacío que se va a ir cargando desde el archivo de texto
	vector<persona>personas;  
	CargarDatos(personas);
	
	
	return 0;
}



/// ****************************************************************************
/// ESTA FUNCION ES PARA CARGAR UN ARCHIVO Y TRABAJAR CON UN VOLUMEN DE DATOS
/// NO TIENEN QUE PRESTARLE NINGUNA ATENCION POR AHORA
void CargarDatos(vector<persona>&personas){
	string dato;
	string linea;
	ifstream arch;
	arch.open("Personas.txt");
	while (!arch.eof()){
		/// leer una linea de datos separada por tabuladores
		getline(arch,linea);
		stringstream aux(linea);
		persona p;
		getline(aux,dato,char(124)); /// lee dni como texto, luego se convierte a int	
		p.dni = atoi(dato.c_str());
		getline(aux,p.nombre,char(124)); /// 
		getline(aux,p.provincia,char(124));
		getline(aux,p.localidad,char(124));
		getline(aux,p.sexo,char(124));
		personas.push_back(p);
	}
	int cant = personas.size();
	arch.close();
	
}
