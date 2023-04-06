#include<iostream>
using namespace std;
int ma(int a, int b) {
	int t;
	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	if (n < 0) {
		n = -n;
	}
	if (m < 0) {
		m = -m;
	}
	if (n == 0 && m == 0) {
		cout << 0;
		return 0;
	}
	else if (n == m || (n == 0 && m != 0) || (n != 0 && m == 0)) {
		cnt = 2;
	}
	if (ma(n, m) == 1) {
		cnt = 1;
	}
	else {
		cnt = 2;
	}
	cout << cnt;
}