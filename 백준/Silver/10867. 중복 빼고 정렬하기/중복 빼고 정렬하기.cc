#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto& e : v) {
		cout << e << " ";
	}
}