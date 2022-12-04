#include<iostream>
using namespace std;
int main() {
	int n, check = -1;
	string s, c;
	cin >> s >> n;
	for (int j = n - 1; j >= 0; j--) {
		int cnt = 0;
		cin >> c;
		if (c.length() != s.length()) {
			continue;
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != c[i]) {
				cnt++;
			}
		}
		if (cnt == 1 && check == -1) {
			check = n - j;
		}
	}
	if (check == -1) {
		cout << n << "\n";
	}
	else {
		cout << check << "\n";
	}
}