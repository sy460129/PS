#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> v;
	queue<int> c;
	int x, y, z, k, t, a = 0, b = 0, count = 0;
	for (int i = 0; i < 9; i++) {
		cin >> x;
		v.push(x);
	}
	for (int i = 0; i < 9; i++) {
		cin >> x;
		c.push(x);
	}
	while (v.size() != 0) {
		k = v.front();
		a += k;
		if (a > b) {
			count = 1;
		}
		t = c.front();
		b += t;
		v.pop();
		c.pop();
	}
	if (count == 1) {
		if (a < b) {
			cout << "Yes";
		}
	}
	else {
		cout << "No";
	}
}