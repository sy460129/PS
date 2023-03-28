#include<vector>
#include<iostream>
using namespace std;
int main() {
	vector<int> v;
	int n, temp;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		v.push_back(n);
	}
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 4; i++) {
			if (v[i] > v[i + 1]) {
				temp = v[i];	
				v[i] = v[i + 1];
				v[i + 1] = temp;
				for (auto& e : v) {
					cout << e << " ";
				}
				cout << "\n";
			}
		}
	}
}