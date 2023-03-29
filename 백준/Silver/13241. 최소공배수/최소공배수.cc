#include<iostream>
using namespace std;
int m(int a, int b) {
	int t;
	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main() {
	unsigned long long int a, b;
	cin >> a >> b;
	cout << a * b / m(a, b);
}