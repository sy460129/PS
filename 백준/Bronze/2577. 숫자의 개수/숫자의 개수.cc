#include<iostream>
using namespace std;
int main() {
	int a, b, c, d;
	int A[10] = { 0,0,0,0,0,0,0,0,0,0 };
	cin >> a;
	cin >> b;
	cin >> c;
	d = a * b * c;
	while (d!=0) {
		int i = d % 10;
		A[i]++;
		d /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << A[i] << "\n";
	}
}