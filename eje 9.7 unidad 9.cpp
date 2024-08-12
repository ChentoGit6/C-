#include <iostream>
#include <matrix>
using namespace std;

int main() {
	int N;
	cout << "Ingrese caantidad de alumnos: "<<endl;
	cin >> N;
	matrix<int>m(N,4,0);
	
	/// 1ro,se completen los DNIs
	int nro,dni,materia,nota;
	for(int i=0;i<N;i++) { 
		cout << "Ingrese nro de alumno de 1 a "<<N<<" : ";cin>>nro;
		cout << "Ingrese dni del alumno : ";cin>>dni;
		m[nro-1][0] = dni;
	}
	/// Ingresar las ternas con las notas
	
	for(int i=0;i<N*3;i++){
		cout << "Ingrese nro de alumno, nro de materia y la nota de dicho alumno"<<endl;
		cin >> nro;
		cin >> materia;
		cin >> nota;
		m[nro-1][materia] = nota;
	}
	int mayor1 = 0;
	int mayor2 = 0;
	int codalum1 = 0;
	int codalum2 = 0;
	
	for(int i=0;i<N;i++) {
		int sumanota = 0;
		for(int j=1;j<4;j++) {
		sumanota += m[i][j];
		}
		/// algoritmo de los 2 mayores
		if (sumanota>mayor1){
			mayor2=mayor1; codalum2=codalum1;
			mayor1=sumanota; codalum1=i;}
		else{
			if (sumanota>mayor2){
				mayor2 = sumanota; codalum2 = i;
			}
		}
	}
	cout << "El 1er alumno con DNI "<<m[codalum1][0] << " tiene la mejor nota, con "<<mayor1<<endl;
	cout << "El 2do alumno con DNI "<<m[codalum2][0] << " tiene la mejor nota, con "<<mayor2<<endl;
	return 0;
}

