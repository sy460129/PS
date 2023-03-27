#include<iostream>
#include<queue>
using namespace std;
int arr[4000001];
int main() {
	queue<int>q;
	queue<int>que;
	int n, cnt = 0, sum = 0;
	for (int i = 2; i <= 4000000; i++) {
		if (arr[i] == 0) {
			q.push(i);
		}
		for (int j = 2; j <= 4000000/i; j ++) {
			arr[j*i] = 1;
		}
	}
	que = q;
	cin >> n;
	int s = q.size();
	for (int i = 0; i < s; i++) {
		sum += q.front();
		q.pop();
		while (sum > n) {
			sum -= que.front();
			que.pop();
		}
		if (sum == n) {
			cnt++;
		}
		if (sum == 0) {
			break;
		}
	}
	cout << cnt << "\n";
}