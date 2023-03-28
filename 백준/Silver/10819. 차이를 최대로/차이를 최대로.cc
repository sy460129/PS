#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
vector<int>vec;
bool check[201];
int res = -2147483648;
void dfs() {
	if (vec.size() == v.size()) {
		int sum = 0;
		for (int i = 1; i < vec.size(); i++) {
			sum += abs(vec[i] - vec[i - 1]);
		}
		res = max(sum, res);
		return;
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
int main() {
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < v.size(); i++) {
		vec.push_back(v[i]);
		check[i] = true;
		dfs();
		vec.pop_back();
		check[i] = false;
	}
	cout << res;
}