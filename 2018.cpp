#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, sum = 0, cnt = 0;
	cin >> n;
	queue<int>q;
	for (int i = 0; i <= n; i++) {
		q.push(i);
		sum += i;
		if (sum >= n) {
			while (sum > n) {
				sum -= q.front();
				q.pop();
			}
			if (sum == n) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
}