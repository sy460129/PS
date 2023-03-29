#include<iostream>
using namespace std;
int main() {
	int n, m, a, t = 0, y = 0, x = 0;
	bool c = true;
	cin >> m >> n;
	string s;
	while (n--) {
		cin >> s >> a;
		if (s == "MOVE") {
			if (t % 4 == 0) {
				while (a--) {
					x++;
				}
			}
			else if (t%4 == 1) {
				while (a--) {
					y++;
				}
			}
			else if (t % 4 == 2) {
				while (a--) {
					x--;
				}
			}
			else {
				while (a--) {
					y--;
				}
			}
		}
		else {
			if (a == 0) {
				t++;
			}
			else {
				t--;
			}
			if (t < 0) {
				t += 4;
			}
		}
		if (x<0 || y<0 || x>m - 1 || y>m - 1) {
			c = false;
		}
	}
	if (c) {
		cout << x << " " << y << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}