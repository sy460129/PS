#include<iostream>
#include<queue>
using namespace std;
int main() {
	priority_queue<int, vector<int>, greater<int>>q;
	int n, l, k, x;
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}
	while (1) {
		if (q.empty()) {
			break;
		}
		if (q.top() <= l) {
			l += k;
			q.pop();
		}
		else {
			break;
		}
	}
	cout << n - q.size() << "\n";
}