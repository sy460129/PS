#include<iostream>
#include<vector>
using namespace std;
vector<char>vec;
vector<char>v;
bool check[201];
void dfs() {
	if (vec.size() == v.size()) {
		for (auto& e : vec) {
			cout << e;
		}
		cout << "\n";
	}
	for (int i = 0; i < v.size(); i++) {
		if (!check[i]) {
			vec.push_back(v[i]);
			check[i] = true;
			dfs();
			vec.pop_back();
			check[i] = false;
		}
	}
}
void track() {
	for (int i = 0; i < v.size(); i++) {
		check[i] = true;
		vec.push_back(v[i]);
		dfs();
		check[i] = false;
		vec.pop_back();
	}
}
int main() {
	int n = 1, t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		cout << "Case # " << n << ":\n";
		for (int i = 0; i < s.length(); i++) {
			v.push_back(s[i]);
		}
		track();
		v.clear(); vec.clear();
		n++;
	}
}