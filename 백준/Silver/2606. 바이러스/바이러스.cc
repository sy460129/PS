#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>>vec;
bool visited[101];
int x = 0;
void dfs(int num) {
	x++;
	visited[num] = true;
	for (int i = 0; i < vec[num].size(); i++) {
		if (!visited[vec[num][i]]) {
			dfs(vec[num][i]);
		}
	}
}
int main() {
	int n, m, a, b;
	cin >> n >> m;
	vec.resize(n + 1);
	while (m--) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i < vec.size(); i++) {
		sort(vec[i].begin(), vec[i].end());
	}
	dfs(1);
	cout << x - 1;
}