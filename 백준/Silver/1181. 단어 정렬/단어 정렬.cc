#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	int n;
	string x;
	cin >> n;
	vector<pair<int, string>>v(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back({ x.length(),x });
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i < v.size(); i++) {
		cout << v[i].second << "\n";
	}
}