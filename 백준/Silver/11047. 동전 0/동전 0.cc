#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int n, k, cnt = 0;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		while (1) {
			if (k / v[i] == 0) {
				break;
			}
			else {
				cnt += k / v[i];
				k %= v[i];
			}
			if (k / v[i] == k) {
				cout << cnt+k;
				return 0;
			}
			else if (k == 0) {
				cout << cnt;
				return 0;
			}
		}
	}
}