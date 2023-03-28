#include<iostream>
using namespace std;
int arr[1000001];
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	arr[0] = 1;
	arr[1] = 1;
	int n;
	for (int i = 2; i < 1000001; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j <= 1000000 / i; j++) {
				arr[i * j] = 1;
			}
		}
	}
	while (1) {
		bool c = false;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (int i = 3; i < 1000001; i++) {
			if (arr[i]==0 && arr[n - i]==0) {
				cout << n << " = " << i << " + " << n - i << "\n";
				c = true;
				break;
			}
		}
		if (!c) {
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
	}
}