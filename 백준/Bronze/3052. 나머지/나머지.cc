#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	vector<int>v;
	int n, x, cnt = 1;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		x = n % 42;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 9; i >=1; i--) {
		if (v[i] == v[i - 1]) {
			v.pop_back();
		}
		else {
			v.pop_back();
			cnt += 1;
		}
	}
	cout << cnt;
}