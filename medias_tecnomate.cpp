#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m;
	cin >> m;
	vector<int>v;
	bool se_puede = false;
	int num;
	for(int i=0;i<m;i++) { 
		cin >> num;
		v.push_back(num);
	}
	for(size_t i=0;i<v.size();i++) { 
		if ((v[i] != 1) or (v[i] != 0)){
			se_puede = true;
			int rta = v.size() + 1;
			cout << rta << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}

