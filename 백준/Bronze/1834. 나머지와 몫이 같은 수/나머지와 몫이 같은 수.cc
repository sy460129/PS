#include<iostream>
using namespace std;
int main() {
	long long m, a, N, c = 0;
	cin >> N;
	a = N + 1;
	m = a;
	for (int i = 1; i <= N - 1; i++) {
		c+=m* i;
	}
	cout << c;
}