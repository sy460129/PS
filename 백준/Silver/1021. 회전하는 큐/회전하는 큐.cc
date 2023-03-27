#include<iostream>
#include<deque>
using namespace std;
int main() {
	int n, m, x, cnt = 0;
	deque<int>d, df, de;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		d.push_back(i);
		df.push_back(i);
		de.push_back(i);
	}
	while (m--) {
		int f = 0, e = 0;
		cin >> x;
		if (d.front() == x) {
			d.pop_front();
			df = d;
			de = d;
		}
		else {
			while (df.front() != x) {
				f++;
				df.push_back(df.front());
				df.pop_front();
			}
			while (de.front() != x) {
				e++;
				de.push_front(de.back());
				de.pop_back();
			}
			if (f < e) {
				d = df;
				cnt += f;
			}
			else {
				d = de;
				cnt += e;
			}
			d.pop_front();
			df = d;
			de = d;
		}
	}
	cout << cnt << "\n";
}