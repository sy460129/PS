#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int arr[1001];
vector<int>v[1001];
queue<int>q;
queue<int>que;
int main() {
	int n, m, t, x, a, cnt = 0;
	cin >> n >> m;
	while (m --) {
		cin >> t >> x;
		t -= 1;
		while (t--) {
			cin >> a;
			v[x].push_back(a);
			arr[a]++;
			x = a;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		cnt++;
		int nx = q.front();
		q.pop();
		que.push(nx);
		for (int i = 0; i < v[nx].size(); i++) {
			int next = v[nx][i];
			arr[next]--;
			if (arr[next] == 0) {
				q.push(next);
			}
		}
	}
	if (cnt == n) {
		while (!que.empty()) {
			cout << que.front() << "\n";
			que.pop();
		}
	}
	else {
		cout << 0;
		return 0;
	}
}