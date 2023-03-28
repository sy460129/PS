#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;
int main() {
	vector<int>v;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		cout << v[7] << "\n";
		v.clear();
	}
}