#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, a, b;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n == 1 || n == 2 && v[0] != v[1]) {
		cout << "A\n";
		return 0;
	}
	if (n == 2 && v[0] == v[1]) {
		cout << v[0];
		return 0;
	}
	if (v[0] == v[1]) {
		a = 1;
		b = 0;
	}
	else {
		a = (v[2] - v[1]) / (v[1] - v[0]);
		b = v[1] - a * v[0];
	}
	for (int i = 0; i < v.size() - 1; i++) {
		if (a * v[i] + b != v[i + 1]) {
			cout << "B";
			return 0;
		}
	}
	cout << v[n-1] * a + b;
}