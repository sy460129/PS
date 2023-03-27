#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int sq(int x, int y) {
	int t;
	t = (x - y) * (x - y);
	return t;
}
int main() {
	int x1, y1, x2, y2, x3, y3;
	double a, b, c, max, min;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double q = (static_cast<double>(y3) - y2) / (x3 - x2);
	double w = (static_cast<double>(y3) - y1) / (x3 - x1);
	double e = (static_cast<double>(y2) - y1) / (x2 - x1);
	if ((x1 == x2 && x1 == x3) || (y1 == y2 && y1 == y3)) {
		cout << -1;
		return 0;
	}
	if (q == w || q == e || w == e) {
		cout << -1;
		return 0;
	}
	a = sqrt(sq(x1, x2) + sq(y1, y2));
	b = sqrt(sq(x1, x3) + sq(y1, y3));
	c = sqrt(sq(x2, x3) + sq(y2, y3));
	if (a >= b) {
		if (a >= c) {
			max = a;
			if (b >= c) {
				min = c;
			}
			else {
				min = b;
			}
		}
		else {
			max = c;
			min = b;
		}
	}
	else {
		if (b >= c) {
			max = b;
			if (a >= c) {
				min = c;
			}
			else {
				min = a;
			}
		}
		else {
			max = c;
			min = a;
		}
	}
	cout << setprecision(18) << 2 * (max - min) << endl;
}