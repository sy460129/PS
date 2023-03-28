#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	vector<string>v(n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		v[i] = s;
	}
	sort(v.begin(), v.end());
	for (auto& e : v) {
		cout << e << "\n";
	}
}