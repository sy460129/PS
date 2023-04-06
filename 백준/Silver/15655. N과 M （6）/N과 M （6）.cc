#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<int>v;
vector<int>vec;
void dfs(int cnt) {
	if (v.size() == m) {
		for (auto& e : v) {
			cout << e << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = cnt; i <= n; i++) {
		if (v.size()<m) {
			v.push_back(vec[i-1]);
			dfs(i+1);
			v.pop_back();
		}
	}
}
int main() {
	int x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	dfs(1);
}