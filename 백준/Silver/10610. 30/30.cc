#include<iostream>
#include<algorithm>
using namespace std;
int cmp(int a, int b) {
	return a > b;
}
int main() {
	int cnt = 0, res = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			cnt = 1;
		}
	}
	if (cnt != 1) {
		cout << -1 << "\n";
		return 0;
	}
	else {
		for (int i = 0; i < s.length(); i++) {
			res += s[i] - '0';
		}
		if (res % 3 == 0) {
			sort(s.begin(), s.end(), cmp);
		}
		else {
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << s;
}