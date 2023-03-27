#include<iostream>
using namespace std;
int main() {
	int N, a, b;
	int X;
	int count = 0;
	cin >> N; //26
	X = N;
	while (1) {
		a = N / 10;
		b = N % 10;
		a += b;
		N = 10 * b + a % 10;
		count++;
		if (X == N) {
			break;
		}
	}
	cout << count;
}