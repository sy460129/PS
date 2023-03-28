#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N, M, x, f, e, mid;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<int>v;
		for (int j = 0; j < N; j++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		cin >> M;
		while (M--) {
			cin >> x;
			int d = 0;
			f = 0, e = N - 1;
			while (f <= e) {
				mid = (f + e) / 2;
				if (v[mid] == x) {
					d = 1;
					break;
				}
				else if (x > v[mid]) {
					f = mid + 1;
					continue;
				}
				else if (x < v[mid]) {
					e = mid - 1;
					continue;
				}
			}
			cout << d << "\n";
		}
	}
}