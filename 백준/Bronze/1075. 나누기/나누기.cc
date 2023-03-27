#include<iostream>
#include<string>
using namespace std;
int main() {
	int N, F;
	cin >> N;
	cin >> F;
	N = N / 100 * 100;
	while (N%F!=0) {
		N += 1;
	}
	N %= 100;
	if (N / 10 == 0) {
		cout << 0;
	}
	cout << N;
}