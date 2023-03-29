#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int dp[100001];
int arr[100001];
int n, k;
queue<int>q;
stack<int>st;
void bfs() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == k) {
			cout << dp[k] << "\n";
			while (x != n) {
				st.push(x);
				x = arr[x];
			}
			break;
		}
		else {
			if (x - 1 >= 0 && dp[x - 1] == 0) {
				q.push(x - 1);
				dp[x - 1] = dp[x] + 1;
				arr[x - 1] = x;
			}
			if (x + 1 <= 100000 && dp[x + 1] == 0) {
				q.push(x + 1);
				dp[x + 1] = dp[x] + 1;
				arr[x + 1] = x;
			}
			if (x * 2 <= 100000 && dp[2 * x] == 0) {
				q.push(2 * x);
				dp[2 * x] = dp[x] + 1;
				arr[2 * x] = x;
			}
		}
	}
}
int main() {
	cin >> n >> k;
	q.push(n);
	bfs();
	cout << n << " ";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << "\n";
}