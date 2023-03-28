#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<long long>v;
	int n;
	v.push_back(0);
	for (long long i = 1; i <= 100; i++) {
		v.push_back(v[i - 1] + i * i);
	}
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << v[n] << "\n";
	}
}