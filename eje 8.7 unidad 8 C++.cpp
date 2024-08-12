#include <iostream>
using namespace std;
/*a) En cierta materia, un alumno es regular si tiene al menos 50% en cada parcial (o
en su recuperatorio, queda siempre la mejor nota) y 60% de asistencia. Y es
promocionado si tiene al menos 80% en cada parcial y 80% de asistencia. Escriba
una función que reciba los datos de un alumno y retorne su condición.
b) Desarrolle un programa cliente que permita ingresar los nombres, el porcentaje
de asistencia, y las 4 calificaciones (parcial 1, parcial 2, recuperatorio 1, y
recuperatorio 2) de cada uno de los N alumnos del curso. El programa debe,
haciendo uso de la función, contar y mostrar cuántos alumnos quedan en condición
de regular y cuántos de promoción.
*/
string alumno(int asistencia,int nota1,int nota2,int recu1, int recu2){
	int mayor1;
	if (nota1 > recu1){
		mayor1 = nota1;
	}else {
		mayor1 = recu1;
	}
	int mayor2;
	if (nota2 > recu2){
		mayor2 = nota2;
	}else {
		mayor2 = recu2;
	}
	if ((mayor1 * mayor2)/2>=80 && asistencia>=80){
		return "Promocionado";
	}else{
		if(mayor1 * mayor2/2>=50 && asistencia>=60){
		return "Regular";
	}
	}
	return "libre";
}
int main() {
	
	cout << "Ingrese los datos del alumno: "<<endl;
	cout << "Nota1: ";
	int nota1;
	cin>> nota1;
	cout << "Nota2: ";
	int nota2;
	cin>> nota2;
	cout << "Recu1: ";
	int recu1;
	cin>> recu1;
	cout << "Recu2: ";
	int recu2;
	cin>> recu2;
	cout << "Asistencia: ";
	int asistencia;
	cin>> asistencia;
	string resultado = alumno(asistencia,nota1,nota2,recu1,recu2);
	cout << resultado;
	return 0;
}

