#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	cout << "Ingresa los coeficientes a, b y c dela ecuación cuadrática";
	int a;
	int b;
	int c;
	int ecua1;
	int ecua2;
	
	cout << "Ingrese a, b y c";
	cin >> a >> b >> c;
	
	ecua1 = (-b-(sqrt(b*b-4*a*c)))2*a;
	cout << ecua1 <<endl;
	ecua2 = (-b+(sqrt(b*b-4*a*c)))2*a;
	cout << ecua2 <<endl;
	return 0;
}

