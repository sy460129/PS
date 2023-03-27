#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int cmp(int a, int b) {
	return a > b;
}
int main() {
	vector<int>v;
	vector<int>vec;
	int n, x, y, res = 0;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x > 0) {
			v.push_back(x);
		}
		else {
			vec.push_back(x);
		}
	}
	sort(v.begin(), v.end());
	sort(vec.begin(), vec.end(),cmp);
	if (v.size() % 2 == 0) {
		while (!v.empty()) {
			x = v.back();
			v.pop_back();
			y = v.back();
			v.pop_back();
			if (x > 0 && y > 0) {
				res += max(x + y, x * y);
			}
		}
	}
	else {
		while (v.size()!=1) {
			x = v.back();
			v.pop_back();
			y = v.back();
			v.pop_back();
			if (x > 0 && y > 0) {
				res += max(x + y, x * y);
			}
		}
		res += v[0];
	}
	if (vec.size() % 2 == 0) {
		while (!vec.empty()) {
			x = vec.back();
			vec.pop_back();
			y = vec.back();
			vec.pop_back();
			if (x < 0 && y < 0) {
				res = res + x * y;
			}
		}
	}
	else {
		while (vec.size() != 1) {
			x = vec.back();
			vec.pop_back();
			y = vec.back();
			vec.pop_back();
			if (x < 0 && y < 0) {
				res = res + x * y;
			}
		}
		res += vec[0];
	}
	cout << res;
}