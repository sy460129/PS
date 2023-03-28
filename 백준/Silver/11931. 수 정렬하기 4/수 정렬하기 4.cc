#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int compare(int a, int b) {
	return a > b;
}
int main() {
	vector<int>v;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(),compare);
	for (auto& e : v) {
		cout << e << "\n";
	}
}