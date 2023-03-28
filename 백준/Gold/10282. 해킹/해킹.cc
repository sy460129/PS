#include<iostream>
#include<queue>
#include<vector>
#define INF 2147483647
using namespace std;
int dp[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
int t, n, d, c, a, b, s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		vector<pair<int, int>>v[10001];
		int m = 0, cnt = 0;
		cin >> n >> d >> c;
		for (int i = 1; i <= 10000; i++) {
			dp[i] = INF;
		}
		dp[c] = 0;
		while(d--) {
			cin >> a >> b >> s;
			v[b].push_back({ a,s });
		}
		q.push({ 0,c });
		while (!q.empty()) {
			int nx = q.top().first;
			int ny = q.top().second;
			q.pop();
			for (int i = 0; i < v[ny].size(); i++) {
				int next = v[ny][i].first;
				int cost = v[ny][i].second;
				if (dp[next] > nx + cost) {
					dp[next] = nx + cost;
					q.push({ dp[next] ,next });
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (dp[i] != INF) {
				cnt++;
				m = max(m, dp[i]);
			}
		}
		cout << cnt << " " << m << "\n";
	}
}