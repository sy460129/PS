#include<iostream>
#include<cmath>
using namespace std;
int sum(int a, int b) {
	int t;
	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main() {
	long long int a, b;
	int c, d;
	cin >> a >> b;
	for (int i = sqrt(a * b); i >= 1; i--) {
		if ((a * b) % i == 0) {
			c = i, d = (a * b) / i;
			if (sum(c, d) == a) {
				break;
			}
		}
	}
	cout << c << " " << d;
}