#include<iostream>
#include<vector>
using namespace std;
int n, m, a, b, x, y;
vector<int>v[101];
bool check[101];
void dfs(int num, int cnt) {
	check[num] = true;
	if (num == b) {
		cout << cnt << "\n";
		exit(0);
	}
	for (int i = 0; i < v[num].size(); i++) {
		if (!check[v[num][i]]) {
			dfs(v[num][i], cnt + 1);
		}
	}
}
int main() {
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(a, 0);
	cout << -1;
}