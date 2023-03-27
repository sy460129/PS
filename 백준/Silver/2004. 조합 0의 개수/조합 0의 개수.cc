#include<iostream>
using namespace std;
int main() {
	long long n, m;
	long long t1 = 0, f1 = 0, t2 = 0, f2 = 0, t3 = 0, f3 = 0;
	cin >> n >> m;
	for (long long i = 2; i <= n; i *= 2) {
		t1 += n / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		f1 += n / i;
	}
	for (long long i = 2; i <= m; i *= 2) {
		t2 += m / i;
	}
	for (long long i = 5; i <= m; i *= 5) {
		f2 += m / i;
	}
	for (long long i = 2; i <= n - m; i *= 2) {
		t3 += (n - m) / i;
	}
	for (long long i = 5; i <= n - m; i *= 5) {
		f3 += (n - m) / i;
	}
	cout << min(t1 - t2 - t3, f1 - f2 - f3);
}