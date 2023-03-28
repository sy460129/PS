#include<iostream>
using namespace std;
bool n[100001];
int main() {
	int x, y, s;
	for (int i = 1; i <= 10000; i++) {
		x = i;
		s = i;
		if (n[i]) {
			continue;
		}
		while (x <= 10000) {
			while (x != 0) {
				y = x % 10;
				x /= 10;
				s += y;
			}
			n[s] = true;
			x = s;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (!n[i]) {
			cout << i << "\n";
		}
	}
}