#include<iostream>
#include<queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k, x, cnt = 0, res = 2147483647;
	queue<int>q;
	cin >> n >> k;
	while (n--) {
		cin >> x;
		q.push(x);
		if (x == 1) {
			cnt++;
		}
		if (cnt == k) {
			while (q.front() != 1) {
				q.pop();
			}
			int t = q.size();
			res = min(res, t);
			q.pop();
			cnt--;
		}
	}
	if (res == 2147483647) {
		cout << -1;
	}
	else {
		cout << res;
	}
}