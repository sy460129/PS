#include<iostream>
#include<deque>
using namespace std;
int main() {
	int n, k, m, cnt = 0, c = 0;
	deque<int>d;
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}
	while (!d.empty()) {
		if (!c) {
			for (int i = 0; i < k - 1; i++) {
				d.push_back(d.front());
				d.pop_front();
			}
			cout << d.front() << "\n";
			d.pop_front();
		}
		else {
			for (int i = 0; i < k - 1; i++) {
				d.push_front(d.back());
				d.pop_back();
			}
			cout << d.back() << "\n";
			d.pop_back();
		}
		cnt++;
		if (cnt == m) {
			if (c) {
				c = false;
			}
			else {
				c = true;
			}
			cnt = 0;
		}
	}
}