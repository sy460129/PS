#include<iostream>
using namespace std;
char arr[25][25];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		int b = 0, w = 0, check_b = 0, check_w = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 'B') {
				if (check_w != 0) {
					check_w = 0;
				}
				check_b++;
				if (check_b >= 3) {
					cout << 0 << "\n";
					return 0;
				}
				b++;
			}
			else {
				if (check_b != 0) {
					check_b = 0;
				}
				check_w++;
				if (check_w >= 3) {
					cout << 0 << "\n";
					return 0;
				}
				w++;
			}
		}
		if (b != w) {
			cout << 0 << "\n";
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		int b = 0, w = 0, check_b = 0, check_w = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[j][i] == 'B') {
				if (check_w != 0) {
					check_w = 0;
				}
				check_b++;
				if (check_b >= 3) {
					cout << 0 << "\n";
					return 0;
				}
				b++;
			}
			else {
				if (check_b != 0) {
					check_b = 0;
				}
				check_w++;
				if (check_w >= 3) {
					cout << 0 << "\n";
					return 0;
				}
				w++;
			}
		}
		if (b != w) {
			cout << 0 << "\n";
			return 0;
		}
	}
	cout << 1 << "\n";
}