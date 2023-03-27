#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v;
	int a, b, x = 0;
	for (int i = 1; i < 1001; i++) {
		for (int j = 0; j < i; j++) {
			v.push_back(i);
		}
	}
	cin >> a >> b;
	for (int i = a-1; i < b; i++) {
		x += v[i];
	}
	cout << x << "\n";
}