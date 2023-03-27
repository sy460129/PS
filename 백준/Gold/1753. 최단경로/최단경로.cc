#include<iostream>
#include<vector>
#include<queue>
#define MAX 20001
#define INF 2147483647
using namespace std;
int dist[MAX];
vector<pair<int, int>>v[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int V, E, start, a, b, c;
	cin >> V >> E >> start;
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	dist[start] = 0;
	q.push({ 0,start });
	while (!q.empty()) {
		int nx = q.top().first;
		int ny = q.top().second;
		q.pop();
		for (int i = 0; i < v[ny].size(); i++) {
			int next = v[ny][i].first;
			int cost = v[ny][i].second;
			if(dist[next]>nx+cost){
				dist[next] = nx + cost;
				q.push({ dist[next], next });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
}
