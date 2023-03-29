#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 2147483647
typedef pair<int, int>p;
int dp[1001];
bool check[1001];
vector<int>v[1001];
priority_queue<p, vector<p>, greater<p>>q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, a, b, x, y;
	cin >> a >> b >> x >> y;
	for (int i = 1; i <= x; i++) {
		dp[i] = INF;
	}
	for (int i = 0; i < y; i++) {
		cin >> n >> m;
		v[n].push_back(m);
		v[m].push_back(n);
	}
	dp[a] = 0;
	q.push({ 0,a });
	while (!q.empty()) {
		n = q.top().first;
		m = q.top().second;
		q.pop();
		if (!check[m]) {
			check[m] = true;
			for (int i = 0; i < v[m].size(); i++) {
				int nx = v[m][i];
				if (dp[nx] > dp[m]) {
					dp[nx] = dp[m] + 1;
					q.push({ dp[nx],nx });
				}
			}
		}
	}
	if (dp[b] == INF) {
		cout << -1;
	}
	else {
		cout << dp[b];
	}
}