#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
int main() {
	bool check = true, c = true;
	int cnt = 0, n;
	string s; cin >> s;
	for (int i = 0; i<s.length(); i++) {
		if (s[i] - '0' == 1) {
			cnt++;
		}
		else if (s[i] - '0' == 0) {
			if (check) continue;
			else v.push_back(0);
		}
		else {
			v.push_back(s[i] - '0');
			check = false;
		}
	}
	while (!v.empty()) {
		n = v.back();
		if (!c) {
			if (n != 0) n--, c = true;
			else if (n == 0) n = 9, c = false;
		}
		else {
			if (n == 0) c = false, n = 10;
		}
		v.pop_back();
		cnt += n;
	}
	cout << cnt;
}