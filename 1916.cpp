#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using p=pair<int,int>;
#define INF 2147483647
vector<p>v[1001];
priority_queue<p, vector<p>, greater<p>>q;
int dp[1001];
int main() {
	int n, m, a, b, c, s, e;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		dp[i]=INF;
	}
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b,c});
	}
	cin >> s >> e;
	dp[s]=0;
	q.push({0,s});
	while (!q.empty()) {
		int nx=q.top().first, ny=q.top().second; q.pop();
		if(dp[ny]!=0 && dp[ny]<nx){
			continue;
		}
		for (int i = 0; i < v[ny].size(); i++) {
			int next = v[ny][i].first;
			int cost = v[ny][i].second;
			if (dp[next] > nx + cost) {
				dp[next] = nx + cost;
				q.push({ dp[next], next });
			}
		}
	}
	cout << dp[e] << "\n";
}