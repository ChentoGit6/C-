#include <iostream>
#include <vector>
using namespace std;
/*En un programa C++ permita ingresar los datos de un vector de tipo unsigned int. Estos datos son enteros de 8 cifras donde las primeras 4 
representan el a�o, las 2 cifras siguientes el mes y las 2 �ltimas el d�a de nacimiento de un grupo de personas. Valide cada dato ingresado 
(debe ser mayor a 19800000 y menor a 20500000) y repita la lectura si no es v�lido. Escriba una funci�n masJoven que reciba el vector como 
par�metro y la fecha actual, y determine la persona m�s joven del grupo. Invoque a la funci�n desde el programa e informe la fecha de nacimiento 
y la edad de la persona m�s Joven (al d�a de hoy: 07 de marzo de 2024).
*/

void masJoven (vector<unsigned int>v, unsigned int fecha_act){
	int mayor = 0;
	for(size_t i=0;i<v.size();i++) { 
		if (v[i] > mayor){
			mayor = v[i];
		}
	}
	unsigned int edad = fecha_act - mayor;
	cout << "La persona mas joven del grupo es la que nace en la fecha "<<mayor<<endl;
	cout << "Su edad es "<<edad<<endl;
}

int main() {
	vector<unsigned int>v;
	unsigned int fecha_nac;
	cin >> fecha_nac;
	
	while (fecha_nac!=0){
		if (fecha_nac > 19800000 and fecha_nac < 20500000){
			v.push_back(fecha_nac);
		}else{
			cout << "D�to err�neo, porfavor ingresa de nuevo o ingrese 0 para terminar"<<endl;
		}
		cin >> fecha_nac;
	}
	unsigned int fecha_act = 20240307;
	
	masJoven (v,fecha_act);
	
	return 0;
}

