#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	vector<double>v;
	int N, C, D;
	double A, B;
	cin >> N;
	cin >> A >> B;
	cin >> C;
	long max = C;
	for (int i = 0; i < N; i++) {
		cin >> D;
		v.push_back(D);
	}
	sort(v.begin(), v.end());
	int K = max / A;
	for (int i = 0; i < N; i++) {
		max += v.back();
		v.pop_back();
		A += B;
		if (K <= max / A) {
			K = max / A;
		}
	}
	cout << K;
}