#include<iostream>
#include<vector>
using namespace std;
vector<int>v[11];
int main() {
	int x, n, m, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> m;
		if (v[x].empty()) {
			v[x].push_back(m);
		}
		else {
			if (v[x].back() != m) {
				sum++;
			}
			v[x].pop_back();
			v[x].push_back(m);
		}
	}
	cout << sum << "\n";
}
