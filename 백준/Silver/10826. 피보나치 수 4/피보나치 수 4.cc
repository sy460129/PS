#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str(string s, string c) {
	int x, y = 0;
	string ans;
	for (int i = 0; i < c.length(); i++) {
		x = (s[i] - '0' + c[i] - '0' + y) % 10;
		y = (s[i] - '0' + c[i] - '0' + y) / 10;
		ans += to_string(x);
	}
	if (y != 0) {
		ans += to_string(y);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string s, c;
	s = "0"; c = "1";
	for (int i = 0; i < n; i++) {
		while (c.length() < s.length()) {
			c += '0';
		}
		string t = str(s, c);
		c = s;
		s = t;
	}
	reverse(s.begin(), s.end());
	cout << s << "\n";
}