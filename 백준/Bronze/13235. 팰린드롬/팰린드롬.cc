#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == s[s.size() - i - 1]) {
			continue;
		}
		else {
			cout << "false";
			return 0;
		}
	}
	cout << "true";
}