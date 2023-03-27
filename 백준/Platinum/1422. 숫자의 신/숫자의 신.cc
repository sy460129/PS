#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string s, string c) {
	if (s.length() == c.length()) {
		return s > c;
	}
	else {
		return s.length() > c.length();
	}
}
bool cm(string s, string c) {
	return s + c > c + s;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<string>v(n);
	vector<string>vec;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vec = v;
	sort(v.begin(), v.end(), cmp);
	for (int i = vec.size(); i < k; i++) {
		vec.push_back(v[0]);
	}
	sort(vec.begin(), vec.end(), cm);
	for (auto& e : vec) {
		cout << e;
	}
}