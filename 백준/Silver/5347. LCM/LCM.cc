#include<iostream>
using namespace std;
int LCM(int a, int b) {
	int t;
	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main() {
	unsigned long long int a, b, n;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << (a * b) / LCM(a, b) << "\n";
	}
}