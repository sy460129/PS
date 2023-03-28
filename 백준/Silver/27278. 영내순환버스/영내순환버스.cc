#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int t[100001];
int tt, ans;
vector<tuple<int ,int ,int>>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, x, y, z, a; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		t[i] += t[i - 1];
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		v.push_back({ x,y,z });
	}
	for (int i = 0; i < v.size(); i++) {
		auto cur = v[i];
		x = get<0>(cur), y = get<1>(cur), z = get<2>(cur);
		if (z > t[x - 1]) {
			tt = t[x - 1];
			a = (z - tt) / t[n] + 1;
			if ((z - tt) % t[n] == 0) a--;
			z = tt + a * t[n];
		}
		else z = t[x - 1];
		if (x < y) z += t[y - 1] - t[x - 1];
		else {
			z += t[n];
			z -= t[x - 1] - t[y - 1];
		}
		ans = max(ans, z);
	}
	cout << ans;
}