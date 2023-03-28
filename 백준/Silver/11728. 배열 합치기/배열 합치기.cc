#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int>v(n + m);
	for (int i = 0; i < n + m; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (auto& e : v) {
		cout << e << " ";
	}
}