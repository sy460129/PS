#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull comb[31][31];
ull a, b;
ull dp(ull x, ull y) {
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (i == j) {
				comb[i][j] = 1;
			}
			else if (i == 0) {
				comb[i][j] = 0;
			}
			else if (j == 0) {
				comb[i][j] = 1;
			}
			else {
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			}
		}
	}
	return comb[x][y];
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> b >> a;
		cout << dp(a, b) << "\n";
	}
}