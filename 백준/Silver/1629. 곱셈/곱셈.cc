#include<iostream>
#include<cmath>
using namespace std;
unsigned long long a, b, c, d;
unsigned long long po(unsigned long long x,unsigned long long m) {
	if (m == 0) {
		return 1;
	}
	else if (m == 1) {
		return x;
	}
		
	if (m % 2 != 0) {
		return po(x, m - 1) * x;
	}
	unsigned long long h = po(x, m / 2);
	h %= c;
	return (h * h) % c;
}
int main() {
	cin >> a >> b >> c;
	d = po(a, b);
	cout << d % c;
}