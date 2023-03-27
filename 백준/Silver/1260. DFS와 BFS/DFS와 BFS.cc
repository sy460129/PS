#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, v;
vector<vector<int>>vec;
bool visited[10001];
void dfs(int num) {
	visited[num] = true;
	cout << num << " ";
	for (int i = 0; i < vec[num].size(); i++) {
		if (!visited[vec[num][i]]) {
			dfs(vec[num][i]);
		}
	}
}
void bfs() {
	queue<int>q;
	q.push(v);
	visited[v] = false;
	cout << v << " ";
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		for (int i = 0; i < vec[num].size(); i++) {
			if (visited[vec[num][i]]) {
				q.push(vec[num][i]);
				visited[vec[num][i]] = false;
				cout << vec[num][i] << " ";
			}
		}
	}
}
int main() {
	cin >> n >> m >> v;
	vec.resize(n + 1);
	int a, b;
	while (m--) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i < vec.size(); i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(v);
	cout << "\n";
	bfs();
}