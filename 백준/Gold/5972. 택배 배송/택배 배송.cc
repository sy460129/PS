#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<pair<int, int>>v[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
int dp[50001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	memset(dp, 500000001, sizeof(dp));
	dp[1] = 0;
	q.push({ 0,1 });
	while (!q.empty()) {
		int nx = q.top().first;
		int ny = q.top().second;
		q.pop();
		for (int i = 0; i < v[ny].size(); i++) {
			int next = v[ny][i].first;
			int cost = v[ny][i].second;
			if (dp[next] > nx + cost) {
				dp[next] = nx + cost;
				q.push({ dp[next],next });
			}
		}
	}
	cout << dp[n] << "\n";
}