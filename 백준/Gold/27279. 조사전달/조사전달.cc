#include <iostream>
#include <algorithm>
using namespace std;
int brr[100002];
int c[100002];
int main() {
	int n, m, x; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		c[x]++;
	}
	for (int i = 1; i <= m; i++) cin >> brr[i];
	sort(brr, brr + m + 1);
	for (int i = m; i>=1; i--) {
		if (brr[i] > c[i]) {
			cout << "NO";
			return 0;
		}
		c[i - 1] += c[i]-brr[i];
		if (c[i] > 100000) break;
	}
	cout << "YES";
}