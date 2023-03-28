#include<iostream>
using namespace std;

int main() {
	bool c = false;
	int x1, y1, a1, b1, x2, y2, a2, b2, w, h;
	cin >> x1 >> y1 >> a1 >> b1 >> x2 >> y2 >> a2 >> b2 >> w >> h;
	if (a1 - a2 >= w && b1 - y1 >= h) {
		c = true;
	}
	else if (x2 - x1 >= w && b1 - y1 >= h) {
		c = true;
	}
	else if (a1 - x1 >= w && y2 - y1 >= h) {
		c = true;
	}
	else if (a1 - x1 >= w && b1 - b2 >= h) {
		c = true;
	}
	if (c) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}