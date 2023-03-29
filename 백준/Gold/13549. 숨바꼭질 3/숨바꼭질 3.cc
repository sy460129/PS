#include<iostream>
#include<queue>
#define MAX 2147483647
using namespace std;
int n, k, res = MAX;
int dp[100001];
bool visit[100001];
queue<int>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == k) {
			res = min(res, dp[x]);
		}
		if (2 * x <= 100000 && visit[2 * x] == false) {
			visit[2 * x] = true;
			dp[2 * x] = dp[x];
			if (res == MAX) {
				q.push(2 * x);
			}
		}
		if (x - 1 >= 0 && visit[x - 1] == false) {
			visit[x - 1] = true;
			dp[x - 1] = dp[x] + 1;
			if (res == MAX) {
				q.push(x - 1);
			}
		}
		if (x + 1 <= 100000 && visit[x + 1] == false) {
			visit[x + 1] = true;
			dp[x + 1] = dp[x] + 1;
			if (res == MAX) {
				q.push(x + 1);
			}
		}
	}
}
int main() {
	cin >> n >> k;
	q.push(n);
	bfs();
	cout << res;
}