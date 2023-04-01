#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string sum(string s, string c) {
	int num, m = 0;
	string res;
	for (int i = 0; i < s.length(); i++) {
		num = (s[i] - '0' + c[i] - '0' + m) % 10;
		res += to_string(num);
		m = (s[i] - '0' + c[i] - '0' + m) / 10;
	}
	if (m != 0) {
		res += to_string(m);
	}
	return res;
}
int main() {
	string s, c, x;
	cin >> s >> c;
	reverse(s.begin(), s.end());
	reverse(c.begin(), c.end());
	while (s.length() > c.length()) {
		c += '0';
	}
	while (c.length() > s.length()) {
		s += '0';
	}
	x = sum(s, c);
	reverse(x.begin(), x.end());
	cout << x << "\n";
}