#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n;
	vector<pair<int, int>>v;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		while (!v.empty()) {
			if (v.back().second < x) {
				v.pop_back();
			}
			else {
				cout << v.back().first << " ";
				v.push_back({ i,x });
				break;
			}
		}
		if (v.empty()) {
			cout << 0 << " ";
			v.push_back({ i,x });
		}
	}
}