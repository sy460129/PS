#include<iostream>
using namespace std;
int arr[301][301];
int main() {
	int n, m, t, a, b, x, y;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> t;
	while (t--) {
		int sum = 0;
		cin >> a >> b >> x >> y;
		for (int i = a; i <= x; i++) {
			for (int j = b; j <= y; j++) {
				sum += arr[i][j];
			}
		}
		cout << sum << "\n";
	}
}