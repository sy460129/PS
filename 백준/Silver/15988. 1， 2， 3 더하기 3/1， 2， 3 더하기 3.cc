#include<iostream>
using namespace std;
unsigned long long d[1000001];
int main() {
	int T, n;
	cin >> T;
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	while(T--) {
		cin >> n;
		for (int i = 4; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
			d[i] %= 1000000009;
		}
		cout << d[n] << "\n";
	}
}