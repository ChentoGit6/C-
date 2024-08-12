#include <iostream>
#include <vector>
using namespace std;

struct datos{
	int nro;
	int cantidad;
};

void ordenar(vector<datos> &a){
	for (size_t i=0; i<a.size(); ++i) {
		for (size_t j=0; j<a.size()-i-1; ++j) {
			if (a[j].nro > a[j+1].nro) {
				// Ordenar de menor a mayor
				datos temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	//Eliminar elementos repetidos
	for(size_t j=0;j<a.size()+1;j++) { 
		if(a[j].nro==a[j+1].nro){
			for(size_t k=j;k<a.size();k++) { 
				a[k]=a[k+1];
			}
			a.resize(a.size()-1);
		}
	}
	
}
	
vector<datos> crear(vector<int> a){
	vector<datos> res;
	datos resultado;
	for(size_t i=0;i<a.size();i++) { 
		resultado.nro=a[i];
		resultado.cantidad=0;
		for(size_t j=0;j<a.size();j++) { 
			if(a[j]==resultado.nro){
				resultado.cantidad++;
			}
		}
		res.push_back(resultado);
	}
	ordenar(res);
	return res;
}

int main() {
	vector<int> v={80,20,80,30,40,30,80};
	
	for(size_t i=0;i<v.size();i++) { 
		cout<<v[i]<<" ";
	}
	cout<<endl;
	vector<datos> x=crear(v);
	
	for(size_t i=0;i<x.size();i++) { 
		cout<<"("<<x[i].nro<<";"<<x[i].cantidad<<")";
	}
	
	return 0;
}

