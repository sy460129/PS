#include<iostream>
#include<vector>
#include<cstring>
int check[51];
using namespace std;
vector<int>v;
vector<int>vec;
int n;
void dfs(int num) {
	if (vec.size() == 6) {
		for (auto& e : vec) {
			cout << e << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = num + 1; i < n; i++) {
		if (check[v[i]] == 0) {
			vec.push_back(v[i]);
			check[v[i]] = 1;
			dfs(i);
			vec.pop_back();
			check[v[i]] = 0;
		}
	}
}
void lotto() {
	for (int i = 0; i < n; i++) {
		vec.push_back(v[i]);
		check[v[i]] = 1;
		dfs(i);
		vec.pop_back();
	}
}
int main() {
	int x;
	while (1) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> x;
			v.push_back(x);
		}
		lotto();
		v.clear();
		vec.clear();
		cout << "\n";
		memset(check, 0, sizeof(check));
	}
}