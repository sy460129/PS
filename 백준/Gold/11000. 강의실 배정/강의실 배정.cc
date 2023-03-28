#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>>q;
priority_queue<int, vector<int>, greater<int>>q2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, a, b, cnt = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		q.push({ a,b });
	}
	if (q.size() == 1) {
		cout << cnt << "\n";
		return 0;
	}
	q2.push(q.top().second);
	q.pop();
	while (!q.empty()) {
		int x = q.top().first;
		int y = q.top().second;
		q.pop();
		if (q2.top() > x) {
			q2.push(y);
		}
		else {
			q2.pop();
			q2.push(y);
		}
	}
	cout << q2.size();
}