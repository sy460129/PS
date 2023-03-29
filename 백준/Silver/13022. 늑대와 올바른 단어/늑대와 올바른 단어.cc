#include<iostream>
#include<string>
using namespace std;
int main() {
	int cnt = 0, wl = 0, ol = 0, ll = 0, fl = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'w') {
			cnt++;
			wl++;
		}
		if (s[i + 1] == 'o') {
			for (int j = i + 1; j < i + 1 + cnt; j++) {
				if (s[j] != 'o') {
					cout << 0;
					return 0;
				}
				ol++;
			}
			for (int j = i + 1 + cnt; j < i + 1 + cnt * 2; j++) {
				if (s[j] != 'l') {
					cout << 0;
					return 0;
				}
				ll++;
			}
			for (int j = i + cnt * 2 + 1; j < i + cnt * 3 + 1; j++) {
				if (s[j] != 'f') {
					cout << 0;
					return 0;
				}
				fl++;
			}
			cnt = 0;
		}
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'w') {
			wl++;
		}
		else if (s[i] == 'o') {
			ol++;
		}
		else if (s[i] == 'l') {
			ll++;
		}
		else {
			fl++;
		}
	}
	if (cnt == 0 && (wl==ol && wl==ll && wl==fl && ol==ll && ol== fl && ll==fl)) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}