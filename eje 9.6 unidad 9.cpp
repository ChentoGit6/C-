#include <iostream>
#include <vector>
using namespace std;
/*Una asociación cooperadora escolar recibe aportes de dinero variable de los
estudiantes asociados. Se leen sin orden alguno los montos aportados durante un
año, y la fecha correspondiente (día y mes). Estos datos terminan con el valor de
monto cero. Informe: a) el total recaudado por mes. b) El mes de menor aporte.
*/

struct aportes {
	float monto;
	int dia;
	int mes;
};
int main() {
	float monto;
	int dia;
	int mes;
	
	vector<aportes>v;
	
	aportes culo;
	cout << "Ingresa el monto:"<<endl;
	cin>> monto;
	while(monto>0){
		cout << "Ingresa el dia:"<<endl;
		cin>>dia;
		cout << "Ingresa el mes:"<<endl;
		cin>>mes;
		culo.monto=monto;
		culo.dia=dia;
		culo.mes=mes;
		v.push_back(culo);
		cout << "Ingresa el monto:"<<endl;
		cin>>monto;
	}
	vector<int>contador(13,0);
	
	for(int i=0;i<v.size();i++) {
		mes = v[i].mes;
		contador [mes] += v[i].monto;
	}
	for(int i=1;i<contador.size();i++) { 
		cout<< "En el mes "<<i<<" se recaudó "<<contador[i]<<"$"<<endl;
	}
	int menor = 99999999;
	int indice = -1;
	for(int i=1;i<contador.size();i++) { 
		if (contador[i]<menor){
			menor = contador[i];
			indice = i;
		}
	}
	cout<<"El mes que tuvo menos aportes es: "<<indice<<endl;

	return 0;
}

