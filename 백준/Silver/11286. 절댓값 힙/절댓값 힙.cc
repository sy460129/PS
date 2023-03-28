#include<iostream>
#include<queue>
using namespace std;
int main() {
	priority_queue<int>q1;
	priority_queue<int, vector<int>, greater<int>>q2;
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x < 0) {
			q1.push(x);
		}
		else if (x > 0) {
			q2.push(x);
		}
		else {
			if (q1.empty() && q2.empty()) {
				cout << 0 << "\n";
			}
			else if (!q1.empty() && !q2.empty()) {
				int a = q1.top();
				int b = q2.top();
				if (abs(a) <= abs(b)) {
					cout << q1.top() << "\n";
					q1.pop();
				}
				else {
					cout << q2.top() << "\n";
					q2.pop();
				}
			}
			else if (q1.empty() && !q2.empty()) {
				cout << q2.top() << "\n";
				q2.pop();
			}
			else if (!q1.empty() && q2.empty()) {
				cout << q1.top() << "\n";
				q1.pop();
			}
		}
	}
}