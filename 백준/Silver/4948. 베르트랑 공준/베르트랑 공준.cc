#include<iostream>
using namespace std;
int arr[246913];
int main() {
	int n, cnt = 0;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= 246913; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j <= 246913 / i; j++) {
				arr[i * j] = 1;
			}
		}
	}
	while (1) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == 0) {
				cnt += 1;
			}
		}
		cout << cnt << "\n";
		cnt = 0;
	}
}