#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string a, string b) {
	return a + b > b + a;
}
int main() {
	int n;
	string s;
	cin >> n;
	vector<string>v;
	while (n--) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	if (v[0][0] == '0') {
		cout << 0;
	}
	else {
		for (auto& e : v) {
			cout << e;
		}
	}
}