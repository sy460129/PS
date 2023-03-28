#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;
ll x[200001];
ll y[200001];
long double dp[200001];
long double dpp[200001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> y[i];
	}
	for (int i = 1; i < n; i++) {
		if (y[i] < y[i + 1]) {
			dp[i] = 3 * sqrt((x[i + 1] - x[i]) * (x[i + 1] - x[i]) + (y[i + 1] - y[i]) * (y[i + 1] - y[i]));
		}
		else if (y[i] == y[i + 1]) {
			dp[i] = 2 * sqrt((x[i + 1] - x[i]) * (x[i + 1] - x[i]) + (y[i + 1] - y[i]) * (y[i + 1] - y[i]));
		}
		else {
			dp[i] = sqrt((x[i + 1] - x[i]) * (x[i + 1] - x[i]) + (y[i + 1] - y[i]) * (y[i + 1] - y[i]));
		}
		dp[i] += dp[i - 1];
	}
	for (int i = n; i > 0; i--) {
		if (y[i] < y[i - 1]) {
			dpp[i] = 3 * sqrt((x[i - 1] - x[i]) * (x[i - 1] - x[i]) + (y[i - 1] - y[i]) * (y[i - 1] - y[i]));
		}
		else if (y[i] == y[i - 1]) {
			dpp[i] = 2 * sqrt((x[i - 1] - x[i]) * (x[i - 1] - x[i]) + (y[i - 1] - y[i]) * (y[i - 1] - y[i]));
		}
		else {
			dpp[i] = sqrt((x[i - 1] - x[i]) * (x[i - 1] - x[i]) + (y[i - 1] - y[i]) * (y[i - 1] - y[i]));
		}
		dpp[i] += dpp[i + 1];
	}
	while (m--) {
		long double d = 0;
		cin >> a >> b;
		if (a < b) {
			d = dp[b-1] - dp[a-1];
		}
		else {
			d = dpp[b+1] - dpp[a+1];
		}
		cout << fixed << setprecision(9) << d << "\n";
	}
}