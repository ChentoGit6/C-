#include <iostream>
#include <vector>
using namespace std;

void eliminar(vector<string> &v, int pos) {
	for (size_t i = pos; i<v.size()-1; ++i)
		v[i] = v[i+1];
	v.resize(v.size()-1);
}

void eliminaDesordenado(vector<string> &v) {
	for (int i=v.size()-1; i>0; --i) { // para atras, porque para adelante falla cuando hay que eliminar 2 consecutivos
		if (v[i] < v[i-1]) {
			eliminar(v,i);
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<string> v;
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	
	eliminaDesordenado(v);
	
	for(string s : v)
		cout << s << " ";
	return 0;
}

