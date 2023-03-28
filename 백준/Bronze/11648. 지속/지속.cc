#include<iostream>
using namespace std;
int main() {
	int a, b = 1, cnt = 0;
	long long n;
	cin >> n;
	while (n / 10 != 0) {
		a = n % 10;
		b *= a;
		n /= 10;
		if (n / 10 == 0) {
			b *= n;
			n = b;
			cnt++;
			b = 1;
		}
	}
	cout << cnt;
}