#include<iostream>
#include<algorithm>
#include<string>
#include<deque>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x;
	bool check, ch;
	string s, c;
	cin >> n;
	while (n--) {
		deque<int> v;
		check = true, ch = true;
		cin >> s >> x >> c;
		for (int i = 0; i < c.length(); i++) {
			string t;
			if ((c[i] == '[' && c[i + 1] != ']') || c[i] == ',') {
				while (c[i + 1] != ',') {
					t += c[i + 1];
					i++;
					if (c[i] == ']') {
						break;
					}
				}
				v.push_back(atoi(t.c_str()));
			}
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'R') {
				if (check) {
					check = false;
				}
				else {
					check = true;
				}
			}
			else {
				if (v.empty()) {
					ch = false;
					break;
				}
				else if (check) {
					v.pop_front();
				}
				else {
					v.pop_back();
				}
			}
		}
		if (!ch) {
			cout << "error\n";
		}
		else {
			cout << "[";
			if (!check) {
				while (!v.empty()) {
					cout << v.back();
					v.pop_back();
					if (!v.empty()) {
						cout << ",";
					}
				}
			}
			else {
				while (!v.empty()) {
					cout << v.front();
					v.pop_front();
					if (!v.empty()) {
						cout << ",";
					}
				}
			}
			cout << "]\n";
		}
	}
}