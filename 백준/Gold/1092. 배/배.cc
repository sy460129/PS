#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mo[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, res = 0, sum = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	vector<int>v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	if (v.back() > arr[n - 1]) {
		cout << -1 << "\n";
		return 0;
	}
	while (!v.empty()) {
		for (int j = 0; j < n; j++) {
			for (int i = v.size()-1; i >= 0; i--) {
				if (arr[j] >= v[i]) {
					mo[j]++;
					v.erase(v.begin() + i);
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		res = max(res, mo[i]);
	}
	cout << res << "\n";
}