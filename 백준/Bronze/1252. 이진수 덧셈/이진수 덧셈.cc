#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string sum(string s, string c) {
	string ans;
	int x,m = 0;
	for (int i = 0; i < s.length(); i++) {
		x = (s[i] - '0' + c[i] - '0' + m) % 2;
		ans += to_string(x);
		m = (s[i] - '0' + c[i] - '0' + m) / 2;
	}
	if (m != 0) {
		ans += '1';
	}
	return ans;
}
int main() {
	string s, c,a;
	vector<char>v;
	cin >> s >> c;
	reverse(s.begin(), s.end());
	reverse(c.begin(), c.end());
	
	while (s.length() > c.length()) {
			c += '0';
	}
	while (s.length() < c.length()) {
		s += '0';
	}
	a= sum(s, c);
	for (int i = 0; i < a.length(); i++) {
		v.push_back(a[i]);
	}
	for (int i = v.size()-1; i >=0; i--) {
		if (v[i]=='0') {
			v.pop_back();
		}
		else {
			break;
		}
		if (v.size() == 0) {
			cout << 0;
			return 0;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
}