#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int t, a, b, c, d, r, x, y, n;
	cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> a >> b >> c >> d;
		cin >> n;
		while (n--) {
			cin >> x >> y >> r;
			if (pow((x - a), 2) + pow((y - b), 2) <= r * r && pow((x - c), 2) + pow((y - d), 2) > r * r) {
				cnt++;
			}
			else if (pow((x - a), 2) + pow((y - b), 2) > r * r && pow((x - c), 2) + pow((y - d), 2) <= r * r) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}