#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, x, sum = 0;
	vector<int>s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (!s.empty()) {
				s.pop_back();
			}
		}
		else {
			s.push_back(x);
		}
	}
	for (auto& e : s) {
		sum += e;
	}
	cout << sum;
}