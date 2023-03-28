#include<iostream>
using namespace std;
int arr[4000001];
int main() {
	int A, B, D, k, t, cnt = 0;
	cin >> A >> B >> D;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= B; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j <= B / i; j++) {
				arr[i * j] = 1;
			}
		}
	}
	for (int i = A; i <= B; i++) {
		if (arr[i] == 0) {
			k = i;
			while (1) {
				t = k % 10;
				if (t == D) {
					cnt += 1;
					break;
				}
				k /= 10;
				if (k == 0) {
					break;
				}
			}
		}
	}
	cout << cnt;
}