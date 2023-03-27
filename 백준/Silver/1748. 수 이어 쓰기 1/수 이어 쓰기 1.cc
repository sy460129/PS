#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n, x, sum = 0, cnt = 0;
	cin >> n;
	x = n;
	while (x!=0) {
		x /= 10;
		cnt++;
	}
	for (int i = 1; i <= cnt - 1; i++) {
		sum += 9 * pow(10, i - 1) * i;
	}
	int c = n - pow(10, cnt - 1) + 1;
	sum += c * cnt;
	cout << sum;
}