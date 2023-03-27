#include <iostream>
#include <vector>
using namespace std;
int dp[11][11];
vector<pair<int,int>>v, vec1, vec2;
int n, ans, cnt;
void dfs1(int j) {
	for (int i = j; i < vec1.size(); i++) {
		bool c = true;
		int x = vec1[i].first, y = vec1[i].second;
		for (int k = 0; k < v.size(); k++) {
			if (abs(v[k].first - x) == abs(v[k].second - y)) c = false;
			if (!c) break;
		}
		if (c) {
			v.push_back({ x,y });
			dfs1(i + 1);
			v.pop_back();
		}
	}
	ans = max(ans, (int)(v.size()));
}
void dfs2(int j) {
	for (int i = j; i < vec2.size(); i++) {
		bool c = true;
		int x = vec2[i].first, y = vec2[i].second;
		for (int k = 0; k < v.size(); k++) {
			if (abs(v[k].first - x) == abs(v[k].second - y)) c = false;
			if (!c) break;
		}
		if (c) {
			v.push_back({ x,y });
			dfs2(i + 1);
			v.pop_back();
		}
	}
	cnt = max(cnt, (int)(v.size()));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dp[i][j];
			if (dp[i][j] == 1) {
				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) vec1.push_back({ i,j });
				else vec2.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < vec1.size(); i++) {
		int x = vec1[i].first, y = vec1[i].second;
		v.push_back({ x,y });
		dfs1(i + 1);
		v.pop_back();
	}
	for (int i = 0; i < vec2.size(); i++) {
		int x = vec2[i].first, y = vec2[i].second;
		v.push_back({ x,y });
		dfs2(i + 1);
		v.pop_back();
	}
	ans += cnt;
	cout << ans;
}