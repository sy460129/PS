#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	vector<char>v;
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		while (k != 0 && v.size() != 0 && v.back() < s[i]) {
			v.pop_back();
			k -= 1;
		}
		v.push_back(s[i]);
	}
	for (int i = 0; i < v.size() - k; i++) {
		cout << v[i];
	}
}