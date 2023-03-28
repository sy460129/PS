#include<iostream>
using namespace std;
long long int t[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int N, M, h = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> t[i];
		h = max(h, t[i]);
	}
	long long int f = 0, e = h;
	long long int ans = 0;
	while (f <= e) {
		long long int s = 0;
		long long int mid = (e + f) / 2;
		for (int i = 0; i <N; i++) {
			if (t[i] - mid > 0) {
				s += t[i] - mid;
			}
		}
		if (s >= M) {
			if (ans < mid) {
				ans = mid;
			}
			f = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans;
}