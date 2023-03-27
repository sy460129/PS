#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, m, x, sum = 0, cnt = 0;
	cin >> n >> m;
	queue<int>q;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
		sum += x;
		if (sum >= m) {
			while (sum > m) {
				sum -= q.front();
				q.pop();
			}
			if (sum == m) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
}