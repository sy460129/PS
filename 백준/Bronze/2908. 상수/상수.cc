#include<iostream>
using namespace std;
int main() {
	int A, B, largest, a = 0, b = 0;
	cin >> A >> B;
	for (int i = 0; i < 3; i++) {
		a += A % 10;
		A /= 10;
		a *= 10;
	}
	for (int i = 0; i < 3; i++) {
		b += B % 10;
		B /= 10;
		b *= 10;
	}
	largest = a;
	if (largest < b) {
		largest = b;
	}
	cout << largest / 10;
}