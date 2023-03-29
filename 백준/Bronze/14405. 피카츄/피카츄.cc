#include<iostream>
#include<string>
using namespace std;
int main() {
	bool c = true;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'p') {
			i++;
			if (i >= s.length() || s[i] != 'i') {
				c = false;
			}
		}
		else if (s[i] == 'k') {
			i++;
			if (i >= s.length() || s[i] != 'a') {
				c = false;
			}
		}
		else if (s[i] == 'c') {
			i++;
			if (i >= s.length() || s[i] == 'h') {
				i++;
				if (i >= s.length() || s[i] != 'u') {
					c = false;
				}
			}
			else if (i >= s.length() || s[i] != 'h') {
				c = false;
			}
		}
		else {
			c = false;
		}
		if (!c) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}