#include<iostream>
using namespace std;
int main() {
	int a, b, cnt = 0;
	cin >> a >> b;
	while (a != b) {
		if (a > b) {
			cout << -1;
			return 0;
		}
		if (b % 10 == 1) {
			b /= 10;
		}
		else if (b % 2 == 0) {
			b /= 2;
		}
		else {
			cout << -1 << "\n";
			return 0;
		}
		cnt++;
	}
	cout << cnt + 1;
}