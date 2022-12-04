#include<iostream>
#include<queue>
using namespace std;
typedef unsigned long long ull;
int main() {
	ull n, m, x, sum = 0, cnt = 0;
	cin >> n >> m;
	priority_queue<ull, vector<ull>, greater<ull>>q;
	while (m--) {
		cin >> x;
		q.push(x);
	}
	while (!q.empty()) {
		sum += q.top();
		cnt++;
		if (sum > n) {
			sum -= q.top();
			cnt--;
		}
		q.pop();
	}
	cout << cnt << "\n";
}