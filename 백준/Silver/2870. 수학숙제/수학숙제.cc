#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
bool check[1001];
bool cmp(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		return a < b;
	}
}
int main() {
	vector<string>v;
	deque<char>d;
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		check[i] = true;
	}
	while (n--) {
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			string c;
			if (check[s[i] - '0']) {
				while (check[s[i] - '0']) {
					d.push_back(s[i]);
					i++;
					if (i >= s.length()) {
						break;
					}
				}
				while (1) {
					if (d.empty()) {
						break;
					}
					if (d.size() != 1 && d.front() == '0') {
						d.pop_front();
					}
					else {
						break;
					}
				}
				while (!d.empty()) {
					c += d.front();
					d.pop_front();
				}
				v.push_back(c);
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (auto& e : v) {
		cout << e << "\n";
	}
}
