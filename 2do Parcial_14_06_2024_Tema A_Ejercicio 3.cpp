#include <iostream>
#include <vector>
using namespace std;

vector<string>pibefuncion(vector<string>v){
	for(int i=1;i<v.size();i++) { 
		if (v[i]>v[i-1]){
			for(int j=i-1;j<v.size()-1;j++) { 
				v[j]=v[j+1];
			}
			v.resize(v.size()-1);
		}
	}
	return v;
}
int main() {
	bool rta = "zoe" <"marta";
	cout<<rta<<endl;
	cout<<"Ingrese los nombres"<<endl;
	vector<string>nombre={"carlos","alba","cintia","saul","zoe","luisa","marta"};
	vector<string>nuevovector=pibefuncion(nombre);
	for(int i=0;i<nuevovector.size();i++) { 
		cout<<nuevovector[i]<<endl;
	}
	return 0;
}

