#include<iostream>
using namespace std;
int main() {
	int n, x;
	cin >> n;
	x = 99;
	if (n < 100) {
		cout << n;
		return 0;
	}
	else {
		for (int i = 100; i <= n; i++) {
			int f = i / 100;
			int s = (i/10) % 10;
			int e = i % 10;
			if ((f - s) == (s - e)) {
				x++;
			}
		}
		cout << x;
	}
}