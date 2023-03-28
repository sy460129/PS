#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n;
int arr[126][126];
int visit[126][126];
typedef tuple<int, int, int>t;
priority_queue<t, vector<t>, greater<t>>q;
int bfs() {
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int sum = get<0>(cur);
			int nx = get<1>(cur) + dx[i];
			int ny = get<2>(cur) + dy[i];
			if (get<1>(cur) == n && get<2>(cur) == n) {
				return sum;
			}
			if (nx<1 || ny<1 || nx>n || ny>n) {
				continue;
			}
			if (visit[nx][ny] == 0) {
				q.push({ sum + arr[nx][ny],nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
}
int main() {
	int k = 1;
	while(1) {
		cin >> n;
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		if (n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		q.push({ arr[1][1],1,1 });
		visit[1][1] = 1;
		cout << "Problem " << k << ": " << bfs() << "\n";
		while (!q.empty()) {
			q.pop();
		}
		k++;
	}
}