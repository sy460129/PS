#include<iostream>
#include<vector>
using namespace std;
vector<int>v[201];
bool visit[201];
int arr[201];
int n, m, t, x, cnt = 0;
bool dfs(int num) {
	for (int i = 0; i < v[num].size(); i++) {
		int a = v[num][i];
		if (visit[a]) {
			continue;
		}
		visit[a] = true;
		if (arr[a] == 0 || dfs(arr[a])) {
			arr[a] = num;
			return true;
		}
	}
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		while (t--) {
			cin >> x;
			v[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		fill(visit, visit + 201, false);
		if (dfs(i)) {
			cnt++;
		}
	}
	cout << cnt << "\n";
}