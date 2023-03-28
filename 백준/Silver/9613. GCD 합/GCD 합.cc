#include<iostream>
#include<vector>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		long long x, sum = 0;
		cin >> n;
		vector<int>v;
		while (n--) {
			cin >> x;
			v.push_back(x);
		}
		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				sum += gcd(v[i], v[j]);
			}
		}
		cout << sum << "\n";
	}
}