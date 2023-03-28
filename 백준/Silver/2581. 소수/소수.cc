#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int>v;
	queue<int>t;
	int N, M, x, c = 0;
	cin >> M;
	cin >> N;
	for (int i = M; i <= N; i++) {
		v.push(i);
	}
	while (v.size() != 0) {
		int m = 2;
		x = v.front();
		if (x == 2) {
			t.push(x);
			c += m;
		}
		while (x > m) {
			if (x % m == 0) {
				break;
			}
			m += 1;
			if (x == m) {
				t.push(x);
				c += m;
			}
		}
		v.pop();
	}
	if (c == 0) {
		cout << -1;
	}
	else {
		cout << c << "\n" << t.front();
	}
}
