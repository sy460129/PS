#include<iostream>
#include<vector>
using namespace std;
vector<int>v[1001];
bool visit[1001];
int arr[1001];
int n, m, a, b, t, cnt;
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
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a >> b;
			for (int j = a; j <= b; j++) {
				v[i].push_back(j);
			}
		}
		for (int i = 1; i <= m; i++) {
			fill(visit, visit + 1001, false);
			if (dfs(i)) {
				cnt++;
			}
		}
		cout << cnt << "\n";
		for (int i = 1; i <= 1000; i++) {
			v[i].clear();
		}
		fill(arr, arr + 1001, 0);
	}
}
