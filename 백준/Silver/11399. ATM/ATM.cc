#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, s = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] * n;
		n--;
	}
	for (auto& e : v) {
		s += e;
	}
	cout << s;
}