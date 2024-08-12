#include <iostream>
#include <vector>
using namespace std;
/*Una entidad bancaria desea procesar los movimientos de la cuenta corriente de un día de su cartera de clientes. Por cada cliente
se tiene: Nro de cuenta, apellido y nombres, saldo y el máximo importe con el que puede operar en descubierto*. Escriba un programa
C++ que incialmente haga la carga de los datos de los N clientes del banco. a) Luego, el programa debe permitir la carga de los 
movimientos del día. Los datos son: nro de cuenta, tipo de movimiento, importe. Los tipos de movimiento pueden ser 1-depósitos, 
2-transferencias recibidas o 3-transferencias hechas. La carga de movimientos termina con nro de cuenta 0. b) Codifique una función
que retorne la lista de movimientos de un cliente, y otra función que use esa sublista para actualizar el saldo de ese cliente. 
c)Utilizando las funciones de (b) actualice los saldos de todos los clientes e informe por pantalla cuáles clientes terminan con un
saldo negativo que supere su mayor importe permitido para descubierto. Nota: ""Descubierto" es cuando queda un saldo negativo. 
Ej: Si en la cuenta del banco se dispone de $10.000 y se efectúan pagos por $15.000; el banco lo admite y la cuenta tiene $5000 de 
descubierto. Muchos bancos tienen acuerdos con clientes para operar en descubierto.
*/

struct cliente {
	int nroc;
	string apynomb;
	float saldo;
	float descub;
};

struct movimientos {
	int numc;
	int mov;
	float import;
};

int buscar (vector<movimientos>f, int num){
	for(size_t i=0;i<f.size();i++) { 
		if (f[i].numc == num){
			return i;
		}
	}
	return -1;
}

float saldoact (vector<movimientos>lista){
	float suma = 0;
	for(size_t i=0;i<lista.size();i++) { 
		suma += lista[i].import;
	}	
	return suma;
}

vector<movimientos> func (int num, vector<movimientos>f){
	vector<movimientos>lista;
	for(size_t i=0;i<f.size();i++) { 
		int pos = buscar (f,num);
		if (pos != -1){
			lista.push_back(f[i]);
		}
	}
	return lista;
}

int main() {
	int N;
	cout << "Ingrese la cantidad de clientes: "; cin >> N;
	vector<cliente>v(N);
	cout << "Inicie la carga de los "<< N <<" clientes:"<< endl; 
	for(size_t i=0;i<v.size();i++) { 
		cout << "  - Cliente "<< i+1 <<":"<< endl;
		cout << "    * Número de cuenta: "; cin >> v[i].nroc;
		cout << "    * Apellido y Nombre: "; cin >> v[i].apynomb;
		cout << "    * Saldo en la cuenta: "; cin >> v[i].saldo;
		cout << "    * Máximo importe que puede operar en descubierto: "; cin >> v[i].descub;
	}
	
	int numc, mov;
	float import;
	vector<movimientos>f;
	cout << "Veremos los movimientos del día"<< endl;
	cout << "   - Ingrese número de cuenta: "; cin >> numc;
	while (numc != 0){
		cout << "   - Ingrese el tipo de movimiento: "; cin >> mov;
		cout << "   - Ingrese el importe: "; cin >> import;
		movimientos p;
		p.numc = numc; p.mov = mov; p.import = import;
		f.push_back(p);
		cout << "   - Ingrese número de cuenta: "; cin >> numc;
	}
	
//	cout << "Lista de movimientos de los clientes "<< endl;
//	for(size_t i=0;i<v.size();i++) { 
//		for(size_t j=0;j<f.size();j++) { 
//			vector<movimientos>lista = func(f[j].numc,f);
//			cout << "   - Nro. de cuenta: "<< f[j].numc << endl;
//			for(size_t k=0;k<lista.size();k++) { 
//				cout << "   - Movmiento: "<< lista[k].mov << endl;;
//				cout << "   - Importe: "<< lista[k].import << endl;
//				
//			}
//			float sald = saldoact(lista);
//			if (v[i].nroc == f[j].numc){
//				cout << "Su saldo actualizado es: "<< v[i].saldo - sald <<endl;
//				break;
//			}
//		}
//	}
	vector<float>lista(N);
	for(size_t i=0;i<v.size();i++) { 
		for(size_t j=0;j<f.size();j++) { 
			if (v[i].nroc == f[j].numc){
				lista[i] += f[j].import;
			}
		}	
	}
	int total = 0;
	for(size_t i=0;i<v.size();i++) { 
		total = v[i].saldo + v[i].descub;
		v[i].saldo -= lista[i];
		if (total < lista[i]){
			cout << v[i].apynomb << "superó su limite en descubierto"<< endl;
		}
	}
	
	return 0;
}

