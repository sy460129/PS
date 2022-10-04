#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	queue<int>q;
	vector<int>v;
	int n, x, y;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		x=q.front();
		v.push_back(x);
		q.pop();
		y = q.front();
		q.push(y);
		q.pop();
	}
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << q.front();
}