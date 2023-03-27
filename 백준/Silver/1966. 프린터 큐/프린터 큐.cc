#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int t, n, m, x, cnt;
	queue<pair<int, int>>q;
	vector<int>v;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> x;
			q.push({ x,i });
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		while (!q.empty()) {
			if (v[n - 1] != q.front().first) {
				q.push({ q.front().first, q.front().second });
				q.pop();
			}
			else {
				if (q.front().second == m) {
					cout << cnt + 1 << "\n";
					break;
				}
				else {
					n--;
					cnt++;
					q.pop();
				}
			}
		}
		while (q.size()!=0) {
			q.pop();
		}
		v.clear();
	}
}