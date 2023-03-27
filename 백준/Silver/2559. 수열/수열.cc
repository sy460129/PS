#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, k, i, j, ma = -999999999, sum = 0;
	queue<int>q;
	cin >> n >> k;
	int* a = new int[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n; i++) {
		if (q.size() < k) {
			sum += a[i];
			q.push(a[i]);
		}
		else {
			if (sum > ma) {
				ma = sum;
			}
			sum += a[i];
			q.push(a[i]);
			sum -= q.front();
			q.pop();
		}
	}
	ma = max(ma, sum);
	cout << ma << "\n";
}