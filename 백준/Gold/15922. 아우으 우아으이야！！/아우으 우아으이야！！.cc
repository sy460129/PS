#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, a, b, start = -2147483648, res = 0;
	cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first > start) {
			start = v[i].first;
			res += v[i].second - v[i].first;
			start = v[i].second;
		}
		else if (v[i].first<=start && v[i].second >start) {
			res += v[i].second - start;
			start = v[i].second;
		}
	}
	cout << res << "\n";
}