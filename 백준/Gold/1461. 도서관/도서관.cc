#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m, x;
	cin >> n >> m;
	vector<int>v1, v2;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > 0) {
			v1.push_back(x);
		}
		else {
			v2.push_back(-x);
		}
	}
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	int sum = 0, cnt = 0, res = 0, k = 0, check = 0;
	if (v1.empty()) {
		for (int i = 0; i < v2.size(); i++) {
			cnt++;
			sum = max(sum, v2[i]);
			if (cnt == m) {
				check++;
				if (check == 1) {
					res += sum;
					sum = 0;
					cnt = 0;
				}
				else {
					res += sum * 2;
					sum = 0;
					cnt = 0;
				}
			}
		}
		if (check < 1) {
			res += sum;
		}
		else {
			res += sum * 2;
		}
	}
	else if (v2.empty()) {
		for (int i = 0; i < v1.size(); i++) {
			cnt++;
			sum = max(sum, v1[i]);
			if (cnt == m) {
				check++;
				if (check == 1) {
					res += sum;
					sum = 0;
					cnt = 0;
				}
				else {
					res += sum * 2;
					sum = 0;
					cnt = 0;
				}
			}
		}
		if (check < 1) {
			res += sum;
		}
		else {
			res += sum * 2;
		}
	}
	else if (abs(v1.front()) > abs(v2.front())) {
		for (int i = 0; i < v2.size(); i++) {
			cnt++;
			sum = max(sum, v2[i]);
			if (cnt == m) {
				res += sum * 2;
				sum = 0;
				cnt = 0;
			}
		}
		res += sum * 2;
		cnt = 0, sum = 0;
		for (int i = 0; i < v1.size(); i++) {
			cnt++;
			sum = max(sum, v1[i]);
			if (cnt == m) {
				check++;
				if (check == 1) {
					res += sum;
					sum = 0;
					cnt = 0;
				}
				else {
					res += sum * 2;
					sum = 0;
					cnt = 0;
				}
			}
		}
		if (check < 1) {
			res += sum;
		}
		else {
			res += sum * 2;
		}
	}
	else {
		for (int i = 0; i < v1.size(); i++) {
			cnt++;
			sum = max(sum, v1[i]);
			if (cnt == m) {
				res += sum * 2;
				sum = 0;
				cnt = 0;
			}
		}
		res += sum * 2;
		cnt = 0, sum = 0;
		for (int i = 0; i < v2.size(); i++) {
			cnt++;
			sum = max(sum, v2[i]);
			if (cnt == m) {
				check++;
				if (check == 1) {
					res += sum;
					sum = 0;
					cnt = 0;
				}
				else {
					res += sum * 2;
					sum = 0;
					cnt = 0;
				}
			}
		}
		if (check < 1) {
			res += sum;
		}
		else {
			res += sum * 2;
		}
	}
	cout << res << "\n";
}