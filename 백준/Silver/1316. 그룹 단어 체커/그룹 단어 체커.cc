#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n, cnt = 0;
	string s;
	vector<char>v;
	vector<char>vec;
	cin >> n;
	while (n--) {
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			v.push_back(s[i]);
			vec.push_back(s[i]);
		}
		sort(vec.begin(), vec.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		sort(v.begin(), v.end());
		if (v == vec) {
			cnt++;
		}
		v.clear();
		vec.clear();
	}
	cout << cnt;
}