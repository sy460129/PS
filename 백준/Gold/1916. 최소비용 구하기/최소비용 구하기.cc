#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 2147483647
vector<pair<int, int>>v[1001];
priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int ,int>>>q;
int dist[1001];
int main() {
	int n, m, a, b, c, start, end;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> start >> end;
	dist[start] = 0;
	q.push({ 0,start });
	while (!q.empty()) {
		int nx = q.top().first;
		int ny = q.top().second;
		q.pop();
		if(dist[ny]!=0 && dist[ny]<nx){
			continue;
		}
		for (int i = 0; i < v[ny].size(); i++) {
			int next = v[ny][i].first;
			int cost = v[ny][i].second;
			if (dist[next] > nx + cost) {
				dist[next] = nx + cost;
				q.push({ dist[next], next });
			}
		}
	}
	cout << dist[end] << "\n";
}