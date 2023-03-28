#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check[1001];
vector<vector<int>>v;
void dfs(int num) {
	check[num] = true;
	for (int i = 0; i < v[num].size(); i++) {
		if (!check[v[num][i]]) {
			dfs(v[num][i]);
		}
	}
}
int main() {
	int n, m, a, b, cnt = 0;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < v.size(); i++) {
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}