
#include<iostream>
#include<vector>
using namespace std;
int main() {
	string s, c;
	bool check = true;
	vector<char>v;
	cin >> s >> c;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i]);
		check = true;
		if (v.back() == c[c.length() - 1]) {
			for (int j = 0; j < c.length(); j++) {
				if (c[c.length() - 1 - j] != v[v.size() - 1 - j]) {
					check = false;
				}
			}
			if (check) {
				for (int k = 0; k < c.length(); k++) {
					v.pop_back();
				}
			}
		}
	}
	if (v.empty()) {
		cout << "FRULA\n";
	}
	for (auto& e : v) {
		cout << e;
	}
}