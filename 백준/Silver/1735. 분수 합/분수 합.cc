#include<iostream>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int a, b, c, d, f, e, t;
	cin >> a >> b;
	cin >> c >> d;
	f=a*d+c*b;
	e=b*d;
	t=gcd(f, e);
	cout << f/t << " " << e/t;
}