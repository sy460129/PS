#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, x, a, b, sum = 0;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>>q;
	while (n--) {
		cin >> x;
		q.push(x);
	}
	while (q.size() != 1) {
		a = q.top();
		q.pop();
		b = q.top();
		sum += (a + b);
		q.pop();
		q.push(a + b);
	}
	cout << sum;
}