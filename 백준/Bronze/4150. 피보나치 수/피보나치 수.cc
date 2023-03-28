#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string str(string s, string c) {
	reverse(s.begin(), s.end());
	reverse(c.begin(), c.end());
	while (s.length() > c.length()) {
		c += '0';
	}
	string res;
	int x, y = 0;
	for (int i = 0; i < s.length(); i++) {
		x = (s[i] - '0' + c[i] - '0' + y) % 10;
		res += to_string(x);
		y = (s[i] - '0' + c[i] - '0' + y) / 10;
	}
	if (y != 0) {
		res += "1";
	}
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	int n;
	cin >> n;
	vector<string>v;
	v.push_back("0");
	v.push_back("1");
	for (int i = 2; i <= n; i++) {
		v.push_back(str(v[i-1],v[i-2]));
	}
	cout << v[n];
}