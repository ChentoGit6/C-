#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float rad;
	float area;
	float perim;
	
	const float PI=3.1416;
	
	cout << "Ingrese el radio: "<<endl;
	cin>>rad;++
	
	area = PI*rad*rad;
	perim = PI*2*rad;
	cout<<"El área es: "<<area<<endl;
	cout<<"El perimetro es: "<<perim<<endl;
	return 0;
}

