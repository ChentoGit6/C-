#include <iostream>
using namespace std; /// escribir el prototipo arriba

int triple(int number);


int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	int caca = triple(N);
	int caca2 = triple (20);
	cout << caca << endl;
	cout << caca2;
	return 0;
}

int triple(int number){ /// aca la funcion del prototipo
	int eltriple = number * 3;
	return eltriple;
}
