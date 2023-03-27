#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int>p;
vector<p>v[1001];
int dp[1001];
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, x, a, b, c, sum = 0;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	dp[x] = 0;
	priority_queue<p, vector<p>, greater<p>>q, q1;
	fill(arr, arr + 1001, 2147483647);
	q1.push({ 0,x });
	while (!q1.empty()) {
		int x = q1.top().first, y = q1.top().second;
		q1.pop();
		for (int j = 0; j < v[y].size(); j++) {
			int next = v[y][j].first;
			int cost = v[y][j].second;
			if (arr[next] > x + cost) {
				arr[next] = x + cost;
				q1.push({ arr[next], next });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i == x) {
			continue;
		}
		else {
			q.push({ 0,i });
			fill(dp, dp + 1001, 2147483647);
			while (!q.empty()) {
				int x = q.top().first, y = q.top().second;
				q.pop();
				for (int j = 0; j < v[y].size(); j++) {
					int next = v[y][j].first;
					int cost = v[y][j].second;
					if (dp[next] > x + cost) {
						dp[next] = x + cost;
						q.push({ dp[next], next });
					}
				}
			}
			sum = max(sum, dp[x] + arr[i]);
		}
	}
	cout << sum << "\n";
}