#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<char>v;
vector<char>vec;
bool check[1000001];
void dfs() {
	if (vec.size() == v.size()) {
		for (auto& e : vec) {
			cout << e;
		}
		cout << "\n";
		return;
	}
	char p = ' ';
	for (int i = 0; i < v.size(); i++) {
		if (!check[i] && p!=v[i]) {
			check[i] = true;
			vec.push_back(v[i]);
			p = v[i];
			dfs();
			vec.pop_back();
			check[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			v.push_back(s[i]);
		}
		sort(v.begin(), v.end());
		dfs();
		v.clear(); vec.clear();
	}
}