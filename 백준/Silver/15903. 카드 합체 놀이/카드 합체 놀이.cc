#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, m, x;
	unsigned long long sum = 0;
	priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>>q;
	cin >> n >> m;
	while (n--) {
		cin >> x;
		q.push(x);
	}
	while (m--) {
		unsigned long long a = q.top();
		q.pop();
		unsigned long long b = q.top();
		q.pop();
		q.push(a + b);
		q.push(a + b);
	}
	while(!q.empty()) {
		sum += q.top();
		q.pop();
	}
	cout << sum << "\n";
}