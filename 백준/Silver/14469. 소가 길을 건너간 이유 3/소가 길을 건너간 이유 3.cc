#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int>p;
priority_queue<p, vector<p>, greater<p>>q;
int main() {
	int n, a, b, res = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		q.push({ a,b });
	}
	while (!q.empty()) {
		int x = q.top().first;
		int y = q.top().second;
		q.pop();
		if (res <= x) {
			res = x;
		}
		res += y;
	}
	cout << res;
}