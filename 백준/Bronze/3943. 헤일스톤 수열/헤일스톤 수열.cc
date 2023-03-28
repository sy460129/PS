#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, max;
	cin >> n;
	while (n--) {
		cin >> x;
		max = x;
		while (1) {
			if (x == 1) {
				cout << max << "\n";
				break;
			}
			if (x % 2 != 0) {
				x = x * 3 + 1;
				if (x > max) {
					max = x;
				}
			}
			else {
				x /= 2;
			}
		}
	}
}