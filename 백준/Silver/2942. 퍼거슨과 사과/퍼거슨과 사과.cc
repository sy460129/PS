#include<iostream>
#include<vector>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, t, max = 1;
	vector<int>v;
	cin >> n >> x;
	t = gcd(n, x);
	while (1) {
		if (t % max == 0) v.push_back(max);
		max++;
		if (t == max) {
			v.push_back(max);
			break;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " " << n / v[i] << " " << x / v[i] << "\n";
	}
}