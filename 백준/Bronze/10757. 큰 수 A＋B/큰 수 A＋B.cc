#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int x, n = 0;
	string s, c, res;
	cin >> s >> c;
	reverse(s.begin(), s.end());
	reverse(c.begin(), c.end());
	while (s.length() > c.length()) {
		c += '0';
	}
	while (c.length() > s.length()) {
		s += '0';
	}
	for (int i = 0; i < s.length(); i++) {
		x = (s[i] - '0' + c[i] - '0' + n) % 10;
		res += to_string(x);
		n = (s[i] - '0' + c[i] - '0' + n) / 10;
	}
	if (n != 0) {
		res += to_string(n);
	}
	reverse(res.begin(), res.end());
	cout << res;
}