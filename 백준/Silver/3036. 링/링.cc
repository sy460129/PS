#include<iostream>
#include<queue>
using namespace std;
int main() {
	int N, r, f, a, m = 2;
	queue<int>q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> r;
		q.push(r);
	}
	f = q.front();
	a = f;
	while (1) {
		q.pop();
		if (q.empty() == true) {
			break;
		}
		while (1) {
			if (q.front() % m == 0 && f % m == 0) {
				q.front() /= m;
				f /= m;
			}
			else {
				m += 1;
			}
			if (m > f || m > q.front()) {
				cout << f << "/" << q.front() << "\n";
				break;
			}
		}
		m = 2;
		f = a;
	}
}