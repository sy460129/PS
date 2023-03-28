#include<iostream>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n;
	while (n--) {
		int cnt = 0, x = 0;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				cnt++;
			}
			else {
				cnt--;
			}
			if (cnt < 0) {
				x = 1;
			}
		}
		if (cnt != 0 || x==1) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
	}
}