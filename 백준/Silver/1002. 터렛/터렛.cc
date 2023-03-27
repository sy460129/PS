#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int T, x1, y1, r1, x2, y2, r2;
	double s;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		s = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				cout << -1 << "\n";
			}
			else {
				cout << 0 << "\n";
				continue;
			}
		}
		else if (s > r1 + r2 || s + r1 < r2 || s + r2 < r1) {
			cout << 0 << "\n";
		}
		else if (s == r1 + r2 || s + r1 == r2 || s + r2 == r1) {
			cout << 1 << "\n";
		}
		else {
			cout << 2 << "\n";
		}
	}
}