#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v;
	int N, x = 0 , max = 1;
	while (1) {
		cin >> N;
		if (N == -1) {
			return 0;
		}
		while (N != max) {
			if (N % max == 0) {
				v.push_back(max);
			}
			max += 1;
		}
		for (auto& e : v) {
			x += e;
		}
		if (x == N) {
			cout << N << " = ";
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
				if (i != v.size() - 1) {
					cout << " + ";
				}
			}
			cout << "\n";
		}
		else {
			cout << N << " is NOT perfect." << "\n";
		}
		max = 1;
		x = 0;
		v.clear();
	}
}