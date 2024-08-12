#include <iostream>
#include <vector>
#include <matrix>
using namespace std;
/* a) Escriba un programa C++ que lea los presupuestos anuales asignados a 10 hospitales de
una provincia al inicio del año 2023 destinado a insumos. Estos datos se leen de a pares: cod hospital
(1..10), monto del presupuesto anual. Luego se deben ingresar los 4 datos de cada gasto efectuado por
cada hospital en el año: cod. hospital (1..10), dia (1..31), mes (1..12), monto.. Estos datos terminan con
cod. hospital cero. El programa debe organizar una matriz de 10 filas (hospitales) por 12 columnas
(meses) donde se indiquen en cada celda los montos por gastos de cada hospital en cada mes del año
2023. Considere que en un mismo mes un mismo hospital puede realizar varios gastos por mes. Luego el
programa de informar: b) Cuáles hospitales terminaron con déficit al finalizar el año (mayores gastos que
el presupuesto anual); c) Por cada mes, cuántos hospitales tuvieron un gasto mayor al mes anterior; d) El
mes y monto de mayor gasto de un hospital que el usuario ingresa como dato.
Nota: para los puntos c) y d) debe utilizar funciones.
*/
int gastomayor (const matrix<float>&gastos, int mes){
	int contador=0;
	for(size_t i=0;i<gastos.size(0);i++) { 
		if (gastos[i][mes]>gastos[i][mes-1])
			++contador;
	}
	return contador;
}
pair<int,float>mayorgasto(matrix<float>gastos, int cod_hospital){
	int monto=-1,mes_mayor;
	for (int mes=0; mes<gastos.size(1)-1;mes++) { 
		if(gastos[cod_hospital][mes]>monto){
			monto = gastos[cod_hospital][mes];
			mes_mayor = mes;
		}
	}
	pair<int,float>p;
	p.first = mes_mayor;
	p.second = monto;
	return p;
}
int main() {

	vector<float>presupuesto(2);
	for(size_t i=0;i<presupuesto.size();i++) { 
		cout<<"Ingrese el presupuesto del hospital "<<i+1<<": ";
		cin>> presupuesto[i];
	}
	
	matrix<float>gastos(2,2,0);
	int cod_hospital,dia,mes;
	float monto;
	cout<<"Ingrese el código de hospital: ";
	cin>> cod_hospital;
	while (cod_hospital!=0){
		cout<<"Ingrese el dia, mes y monto de los gastos efectuados del hospital "<<cod_hospital<<endl;
		cin>>dia>>mes>>monto;
		gastos[cod_hospital-1][mes-1] += monto;
		cout<<"Ingrese el código de hospital: ";
		cin>> cod_hospital;
	}
	gastos.resize(gastos.size(0),gastos.size(1)+1);
	for(size_t i=0;i<gastos.size(0);i++) { 
		int suma = 0;
		for(size_t j=0;j<gastos.size(1)-1;j++) { 
			suma += gastos[i][j];
		}		
		gastos[i][gastos.size(1)]=suma;
	}
	
	for(size_t i=0;i<gastos.size(0);i++) { 
		if(presupuesto[i]<gastos[i][gastos.size(1)]){
			cout<<"El hospital "<<i+1<<" tiene déficit ya que posee un presupuesto de $"<<presupuesto[i]<<" y sus gastos son $"<<gastos[i][gastos.size(1)]<<endl;
		}
	}
	
	for(size_t mes=1;mes<gastos.size(1)-1;mes++) { 
		cout<<"En el mes "<<mes+1<<" ,"<<gastomayor(gastos,mes)<<" hospitales tuvieron un gasto mayor al mes anterior"<<endl;
	}
	cout<<"Ingrese el código de hospital para saber su mayor gasto y en que mes lo obtuvo: ";
	cin>>cod_hospital;
	pair <int,float>p = mayorgasto(gastos,cod_hospital-1);
	cout<<"En el mes "<<p.first+1<<" obtuvo su mayor gasto, con un total de $"<<p.second;
	return 0;
}

