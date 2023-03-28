#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string dp[1001][1001];
string adds(string v1, string v2) {
	string s;
	unsigned long long sum = 0;
	while (!v1.empty() || !v2.empty() || sum) {
		if (!v1.empty()) {
			sum += v1.back() - '0';
			v1.pop_back();
		}
		if (!v2.empty()) {
			sum += v2.back() - '0';
			v2.pop_back();
		}
		int d = sum % 10;
		sum /= 10;
		s += d + '0';
	}
	reverse(s.begin(), s.end());
	return s;
}
string comb(int n, int m) {
	if (n == m || m == 0) {
		return "1";
	}
	if (m == 1) {
		return to_string(n);
	}
	if (dp[n][m].size()) {
		return dp[n][m];
	}
	string v = adds(comb(n - 1, m - 1), comb(n - 1, m));
	dp[n][m] = v;
	return dp[n][m];
}
int main() {
	int n, m, x;
	cin >> n >> m;
	string t;
	string k = comb(n, m);
	if (k.length() >= 6) {
		for (int i = 0; i < 4; i++) {
			t += k[i];
		}
		for (int j = 4; j < k.length(); j++) {
			t += k[j];
			x = atoi(t.c_str());
			x %= 10007;
			t = to_string(x);
		}
		cout << x;
	}
	else {
		x = atoi(k.c_str());
		cout << x % 10007;
	}
}