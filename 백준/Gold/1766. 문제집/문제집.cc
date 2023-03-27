#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int arr[32001];
vector<int>v[32001];
priority_queue<int, vector<int>, greater<int>>q;
int main() {
	int n, m, x, y;
	cin >> n >> m;
	while (m--) {
		cin >> x >> y;
		v[x].push_back(y);
		arr[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int nx = q.top();
		q.pop();
		cout << nx << " ";
		for (int i = 0; i < v[nx].size(); i++) {
			int next = v[nx][i];
			arr[next]--;
			if (arr[next] == 0) {
				q.push(next);
			}
		}
	}
}