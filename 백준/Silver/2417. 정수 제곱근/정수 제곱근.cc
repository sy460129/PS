#include<iostream>
using namespace std;
int main() {
	unsigned long long n, m, f = 0, e = 2147483648 * 2;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	while (1) {
		m = (f + e) / 2;
		if (m * m > n) e = m - 1;
		else f = m + 1;
		if (m * m >= n && (m-1)*(m-1)<n) break;
	}
	cout << m;
}