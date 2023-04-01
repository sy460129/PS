#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>v;
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		v.push_back(i + v[i - 1]);
	}
	cout << v[n - 1];
}