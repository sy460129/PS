#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int> v;
	int N, L, x;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (auto& e : v) {
		if (e <= L) {
			L += 1;
		}
	}
	cout << L;
}