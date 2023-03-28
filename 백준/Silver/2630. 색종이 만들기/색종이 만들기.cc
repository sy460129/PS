#include <iostream>
using namespace std;
int arr[128][128];
int wh = 0, bl = 0;
void dv(int x, int y, int n) {
	int t;
	t = arr[x][y];
	for (int i = x; i < n + x; i++) {
		for (int j = y; j < n + y; j++) {
			if (t != arr[i][j]) {
				t = -1;
				break;
			}
		}
		if (t == -1) {
			break;
		}
	}
	if (t == 0) {
		wh++;
	}
	else if (t == 1) {
		bl++;
	}
	else {
		dv(x, y, n / 2);
		dv(n / 2 + x, y, n / 2);
		dv(x, n / 2 + y, n / 2);
		dv(n / 2 + x, n / 2 + y, n / 2);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dv(0, 0, n);

	cout << wh << '\n' << bl << '\n';
}