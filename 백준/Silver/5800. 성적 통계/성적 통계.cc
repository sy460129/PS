#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m, x;
	vector<int>v;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int res = 0;
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < m - 1; j++) {
			res = max(res, v[j + 1] - v[j]);
		}
		cout << "Class " << i << "\n";
		cout << "Max " << v[m - 1] << ", " << "Min " << v[0] << ", " << "Largest gap " << res << "\n";
		v.clear();
	}
}