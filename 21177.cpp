#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, x, s;
	long long sum = 0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), cmp);
	s = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] == s - 1) {
			s = v[i];
		}
		else {
			sum += s;
			s = v[i];
		}
	}
	sum += s;
	cout << sum;
}