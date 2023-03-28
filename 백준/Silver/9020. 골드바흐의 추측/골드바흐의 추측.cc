#include<iostream>
using namespace std;
int arr[246913];
int main() {
	int n, T, a, b;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= 246913; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j <= 246913 / i; j++) {
				arr[i * j] = 1;
			}
		}
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		a = n / 2;
		b = n / 2;
		while (1) {
			if (arr[a] == 0 && arr[b] == 0) {
				cout << a << " " << b << "\n";
				break;
			}
			else {
				a -= 1;
				b += 1;
			}
		}
	}
}