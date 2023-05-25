#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, x;
	cin >> n >> m;
	vector<pair<int, int>>v;
	v.push_back({ 0,0 });
	for (int i = 1; i <= n; i++) {
		cin >> x;
		v.push_back({ x + v[i - 1].first,i });
	}
	while (m--) {
		cin >> x;
		int f = 1, e = n;
		while (1) {
			int mid = (f + e) / 2;
			if (f > e) {
				cout << v[mid].second << "\n";
				break;
			}
			if (v[mid].first > x) {
				e = mid - 1;
			}
			else if (v[mid].first < x) {
				f = mid + 1;
			}
			else if (v[mid].first == x) {
				cout << v[mid].second << "\n";
				break;
			}
		}
	}
}