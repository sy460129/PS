#include<iostream>
#include<cmath>
using namespace std;
int arr[10][10];
bool check[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n = 1, x;
	cin >> t;
	while (t--) {
		cin >> x;
		x *= x;
		bool c = true;
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= x; j++) {
				cin >> arr[i][j];
				if (arr[i][j] > x) {
					c = false;
				}
			}
		}
		for (int i = 1; i <= x; i++) {
			fill(check, check + 1001, false);
			for (int j = 1; j <= x; j++) {
				if (check[arr[i][j]] && c) {
					c = false;
				}
				check[arr[i][j]] = true;
			}
			if (!c) {
				break;
			}
		}
		for (int i = 1; i <= x; i++) {
			fill(check, check + 1001, false);
			for (int j = 1; j <= x; j++) {
				if (check[arr[j][i]] && c) {
					c = false;
				}
				check[arr[j][i]] = true;
			}
			if (!c) {
				break;
			}
		}
		int t = 1;
		while (t != x + 1) {
			fill(check, check + 1001, false);
			for (int i = t; i < t + sqrt(x); i++) {
				for (int j = t; j < t + sqrt(x); j++) {
					if (check[arr[i][j]] && c) {
						c = false;
					}
					check[arr[i][j]] = true;
				}
				if (!c) {
					break;
				}
			}
			t += sqrt(x);
		}
		if (!c) {
			cout << "Case #" << n << ": No\n";
		}
		else {
			cout << "Case #" << n << ": Yes\n";
		}
		n++;
	}
}