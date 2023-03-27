#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int>q;
	int n, x, num;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << "<";
	while (!q.empty()) {
		for (int i = 1; i < x; i++) {
			num = q.front();
			q.pop();
			q.push(num);
		}
		cout << q.front();
		q.pop();
		if (q.size()>0) {
			cout << ", ";
		}
	}
	cout << ">";
}