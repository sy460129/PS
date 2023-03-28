#include<iostream>
using namespace std;
int arr[101][101];
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int res = -1, a = 0, b = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 2; j++) {
 			int t = 0, sum = 0;
			while (t < 3) {
				int k = 0;
				while (k < 3) {
					sum += arr[i + k][j + t];
					k++;
				}
				t++;
			}
			if (res == sum) {
				continue;
			}
			res = max(sum, res);
			if (res == sum) {
				a = i, b = j;
			}
		}
	}
	cout << res << "\n";
	cout << a << " " << b;
}