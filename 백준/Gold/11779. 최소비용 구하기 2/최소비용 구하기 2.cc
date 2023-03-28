#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
typedef pair<int, int> p;
vector<p>v[1001];
stack<int>st;
int dp[1001];
int arr[1001];
bool visit[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, a, b, c, start, end;
	cin >> n >> m;
	fill(dp, dp + 1001, 2147483647);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> start >> end;
	dp[start] = 0;
	priority_queue<p, vector<p>, greater<p>>q;
	q.push({ 0,start });
	while (!q.empty()) {
		int x = q.top().first, y = q.top().second;
		q.pop();
		if (!visit[y]) {
			visit[y] = true;
			for (int i = 0; i < v[y].size(); i++) {
				int next = v[y][i].first;
				int cost = v[y][i].second;
				if (dp[next] > x + cost) {
					dp[next] = x + cost;
					arr[next] = y;
					q.push({ dp[next],next });
				}
			}
		}
	}
	cout << dp[end] << "\n";
	st.push(end);
	while (end != start) {
		st.push(arr[end]);
		end = arr[end];
	}
	cout << st.size() << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << "\n";
}