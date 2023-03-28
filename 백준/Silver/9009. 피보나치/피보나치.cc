#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<long long>v = { 0,1,1 };
	vector<long long>vec;
	int N, a, y;
	long long x;
	for (int i = 3; i <= 90; i++) {
		x = v[i - 1] + v[i - 2];
		v.push_back(x);
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		for (int i = 90; i >= 1; i--) {
			if (a >= v[i]) {
				a -= v[i];
				y = v[i];
				vec.push_back(y);
			}
		}
		sort(vec.begin(), vec.end());
		for (auto& e : vec) {
			cout << e << " ";
		}
		vec.clear();
	}
}