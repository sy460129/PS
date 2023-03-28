#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>v[501];
bool check[501];
queue<int>q;
int n, m, a, b, cnt = 0;
void bfs() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (check[v[x][i]]) {
				continue;
			}
			check[v[x][i]] = true;
			cnt++;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	check[1] = true;
	for (int i = 0; i < v[1].size(); i++) {
		q.push(v[1][i]);
		check[v[1][i]] = true;
		cnt++;
	}
	bfs();
	cout << cnt;
}