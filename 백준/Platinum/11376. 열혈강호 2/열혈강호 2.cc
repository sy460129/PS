#include<iostream>
#include<vector>
using namespace std;
vector<int>v[1001];
int arr[1001];
bool visit[1001];
int n, m, a, b, t, cnt = 0;
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
	for (int i = 1; i <= n; i++) {
		cin >> t;
		while (t--) {
			cin >> a;
			v[i].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		int k = 2;
		while (k--) {
			fill(visit, visit + 1001, false);
			if (dfs(i)) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
}