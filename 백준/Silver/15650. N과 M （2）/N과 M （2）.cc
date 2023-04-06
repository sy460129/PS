#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<int>v;
void dfs(int cnt) {
	if (v.size() == m) {
		for (auto& e : v) {
			cout << e << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = cnt; i <= n; i++) {
		if (v.size() < m) {
			v.push_back(i);
			dfs(i+1);
			v.pop_back();
		}
	}
}
int main() {
	cin >> n >> m;
	dfs(1);
}