#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	string s, c;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != 'x') {
			c += s[i];
		}
		if (s[i] == 'x') {
			n = atoi(c.c_str());
			n /= 2;
			if (n == 1) {
				cout << "x";
			}
			else if (n == -1) {
				cout << "-x";
			}
			else {
				cout << n << "x";
			}
			if (s[i + 1] == '+' || s[i + 1] == '-') {
				if (s[i + 2] == '0') {
					cout << s[i] << "+W";
					return 0;
				}
				if (s[i + 2] == '1' && i+2 !=s.length()-1) {
					for (int j = i; j < s.length(); j++) {
						cout << s[j];
					}
				}
				else if(s[i+2]=='1'){
					cout << s[i] << s[i + 1];
				}
				else {
					for (int j = i; j < s.length(); j++) {
						cout << s[j];
					}
				}
			}
			break;
		}
	}
	if (c == s) {
		n = atoi(s.c_str());
		if (n == 0) {
			cout << "W";
		}
		else if (n == 1) {
			cout << "x+W";
		}
		else if (n == -1) {
			cout << "-x+W";
		}
		else {
			cout << n << "x+W";
		}
		return 0;
	}
	cout << "x+W";
}