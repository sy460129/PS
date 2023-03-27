#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<pair<int, int>>v;
	int n, m, a, b, cnt = 0, start = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first > start) {
			start = v[i].first;
		}
		while (start < v[i].second) {
			start += m;
			cnt++;
		}
	}
	cout << cnt << "\n";
}