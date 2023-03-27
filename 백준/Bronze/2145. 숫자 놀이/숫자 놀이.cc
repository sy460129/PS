#include<iostream>
using namespace std;
int main() {
	int N, x = 0;
	while (1) {
		cin >> N;
		if (!N) {
			return 0;
		}
		while (N!=0) {
			x += N % 10;
			N /= 10;
		}
		while (1) {
			if (x / 10 != 0) {
				N = x;
				x = 0;
				while (N != 0) {
					x += N % 10;
					N /= 10;
				}
			}
			else {
				break;
			}
		}
		cout << x << endl;
		x = 0;
	}
}

