#include<iostream>
using namespace std;
int main() {
	int n, a, b, m = 1, max;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		m = 1;
		while (1) {
			if (a % m == 0 && b % m == 0) {
				max = m;
			}
			m++;
			if (m > a || m > b) {
				break;
			}
		}
		cout << (a * b) / max << endl;
	}
}