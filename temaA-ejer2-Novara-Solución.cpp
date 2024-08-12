#include <iostream>
#include <matrix>
using namespace std;

// para el c: la func retorna la cuenta de un solo mes, el main la invoca 11 veces
int gastoCreciente(const matrix<float> &gastos, int mes) {
	int c = 0;
	for (int hos=0; hos<10; ++hos) {
		if (gastos[hos][mes]>gastos[hos][mes-1])
			++c;
	}
	return c;
}

// alternativa para el c: la func retorna los 11 resultados
//vector<int> gastoCreciente(const matrix<float> &gastos) {
//	vector<int> r;
//	for (int mes=1; mes<12; ++mes) {
//		int c = 0;
//		for (int hos=0; hos<10; ++hos) {
//			if (gastos[hos][mes]>gastos[hos][mes-1])
//				++c;
//		}
//		r.push_back(c);
//	}
//	return r;
//}

pair<int,float> mayorGasto(matrix<float> gastos, int hos) {
	int monto=-1, mes_mayor;
	for (int mes=0; mes<12; ++mes) {
		if (gastos[hos][mes]>monto) {
			monto = gastos[hos][mes];
			mes_mayor = mes;
		}
	}
	pair<int,float> p;
	p.first = mes_mayor;
	p.second = monto;
	return p;
//	return {mes_mayor, monto};
}

int main() {
	// a
	vector<float> pres(10);
	for (size_t i=0; i<pres.size(); ++i) {
		int cod, monto;
		cin >> cod >> monto;
		pres[cod-1] = monto;
	}
	
	matrix<float> gastos(10,12,0);
	int cod;
	cin >> cod;
	while (cod!=0) {
		int dia, mes, monto;
		cin >> dia >> mes >> monto;
		gastos[cod-1][mes-1] += monto;
		
		cin >> cod;
	}
	
	// b
	for (int hos=0; hos<10; ++hos) {
		float sum = 0;
		for (int mes=0; mes<12; ++mes)
			sum += gastos[hos][mes];
		if (sum>pres[hos])
			cout << hos+1 << endl;
	}
	
	// c
	for (int mes=1; mes<12; ++mes) {
		cout << mes+1 << ": " << gastoCreciente(gastos,mes) << endl;
	}
	
	// c alternativo
//	vector<int> r = gastoCreciente(gastos);
//	for (int mes=1; mes<12; ++mes) {
//		cout << mes+1 << ": " << r[i-1] << endl;
//	}
	
	// d
	int hos;
	cin >> hos;
	pair<int,float> p = mayorGasto(gastos,hos); // podria retornar solo el mes, y el monto sale de gastos[hos][mes]
	cout << p.first+1 << " $" << p.second << endl;
	
	return 0;
}

