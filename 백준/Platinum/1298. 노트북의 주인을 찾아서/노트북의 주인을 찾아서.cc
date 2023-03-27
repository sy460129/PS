#include<iostream>
#include<vector>
using namespace std;
vector<int>v[101];
int arr[101];
bool visit[101];
int n, m, a, b, cnt = 0;
bool dfs(int num) {
	for (int i = 0; i < v[num].size(); i++) {
		if (visit[v[num][i]]) {
			continue;
		}
		visit[v[num][i]] = true;
		if (arr[v[num][i]] == 0 || dfs(arr[v[num][i]])) {
			arr[v[num][i]] = num;
			return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		fill(visit, visit + 101, false);
		if (dfs(i)) {
			cnt++;
		}
	}
	cout << cnt << "\n";
}