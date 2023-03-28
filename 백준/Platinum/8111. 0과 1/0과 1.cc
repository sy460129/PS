#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
queue<pair<int, string>>q, que;
int t, x;
string ans;
bool visit[20001];
void bfs() {
	while(!q.empty()) {
		int a = q.front().first;
		string b = q.front().second;
		q.pop();
		if (a == 0) {
			q = que;
			ans = b;
			return;
		}
		int i = (a * 10) % x, j = (a * 10 + 1) % x;
		if (!visit[i]) {
			visit[i] = true;
			q.push({ i, b + "0" });
		}
		if (!visit[j]) {
			visit[j] = true;
			q.push({ j, b + "1" });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		ans = "-1";
		cin >> x;
		q.push({ 1,"1" });
		bfs();
		ans == "-1" ? cout << "BRAK\n" : cout << ans << "\n";
		memset(visit, false, sizeof(visit));
	}
}