#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int>v;
	int N, x, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	while (v.size() != 0) {
		int m = 2;
		x = v.back();
		if (x == 1) {
			count++;
		}
		while (x > m) {
			
			if (x % m == 0) {
				count += 1;
				break;
			}
			m += 1;
		}
		v.pop_back();
	}
	cout << N - count;
}