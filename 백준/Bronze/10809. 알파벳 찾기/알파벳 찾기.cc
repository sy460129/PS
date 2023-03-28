#include<iostream>
#include<vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	char x = 'a';
	vector<int>v[26];
	while (1) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == x) {
				v[x - 'a'].push_back(i);
				break;
			}
		}
		if (x == 'z') {
			break;
		}
		x++;
	}
	for (int i = 0; i < 26; i++) {
		if (v[i].empty()) {
			cout << -1 << " ";
		}
		else {
			cout << v[i].back() << " ";
		}
	}
}