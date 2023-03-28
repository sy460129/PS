#include<iostream>
#include<vector>
using namespace std;
int main() {
	string s, c;
	int n;
	vector<string>v;
	bool check;
	cin >> s >> n;
	while (n--) {
		check = true;
		cin >> c;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '*' && s[i] != c[i]) {
				check = false;
			}
		}
		if (check) {
			v.push_back(c);
		}
	}
	cout << v.size() << "\n";
	for (auto& e : v) {
		cout << e << "\n";
	}
}