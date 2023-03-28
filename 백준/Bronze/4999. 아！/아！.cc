#include<iostream>
using namespace std;
int main() {
	int p = 0, t = 0;
	string s, c;
	cin >> s >> c;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a') {
			p++;
		}
	}
	for (int i = 0; i < c.length(); i++) {
		if (c[i] == 'a') {
			t++;
		}
	}
	if (p >= t) {
		cout << "go\n";
	}
	else {
		cout << "no\n";
	}
}