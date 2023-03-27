#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int cnt = 1;
	string s, c;
	cin >> s;
	c = s;
	while (s != "0") {
		cnt = 1;
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != c[i]) {
				cnt = 0;
				break;
			}
		}
		if (cnt == 0) {
			cout << "no" << "\n";
		}
		else {
			cout << "yes" << "\n";
		}
		cin >> s;
		c = s;
	}
}
