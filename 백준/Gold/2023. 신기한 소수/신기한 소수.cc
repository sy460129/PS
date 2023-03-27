#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int a[] = { 2,3,5,7 };
int n, x;
bool check;
void dfs(int num) {
	if (num == n) {
		for (int j = 2; j <= sqrt(x); j++) {
			if (x % j == 0) {
				check = false;
				break;
			}
		}
		if (check) {
			cout << x << "\n";
			return;
		}
	}
	x *= 10;
	for (int i = 1; i <= 9; i += 2) {
		check = true;
		x += i;
		for (int j = 2; j <= sqrt(x); j++) {
			if (x % j == 0) {
				check = false;
				break;
			}
		}
		if (check) {
			dfs(num + 1);
			x -= i;
		}
		else {
			x -= i;
		}
		if (i == 9) {
			x /= 10;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	if (n == 1) {
		for (int i = 0; i < 4; i++) {
			cout << a[i] << "\n";
		}
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		x = a[i];
		dfs(1);
	}
}