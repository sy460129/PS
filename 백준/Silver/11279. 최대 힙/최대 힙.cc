#include<iostream>
#include<queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	priority_queue<int>q;
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (!q.empty()) {
				cout << q.top() << "\n";
				q.pop();
			}
			else {
				cout << "0" << "\n";
			}
		}
		else {
			q.push(x);
		}
	}
}