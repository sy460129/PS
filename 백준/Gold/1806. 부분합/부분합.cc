#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main() {
	queue<int>q;
	int n, m, x, sum = 0, res = 100000001, size = 0;
	cin >> n >> m;
	while (n--) {
		cin >> x;
		sum += x;
		q.push(x);
		while (sum >= m) {
			size = q.size();
			res = min(res, size);
			sum -= q.front();
			q.pop();
		}
	}
	if (size == 0) {
		cout << 0 << "\n";
		return 0;
	}
	cout << res;
}