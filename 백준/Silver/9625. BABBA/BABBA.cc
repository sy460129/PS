#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>>v;
	v.push_back({ 1,0 });
	v.push_back({ 0,1 });
	for (int i = 2; i <= n; i++) {
		v.push_back({ v[i - 1].first + v[i - 2].first ,v[i - 1].second + v[i - 2].second });
	}
	cout << v[n].first << " " << v[n].second;
}