#include<iostream>
#include<queue>
using namespace std;
int n, k, cnt = 0, t = 0;
queue<int>q;
int check[100001];
void bfs() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == k) {
			cout << check[x] << "\n";
			break;
		}
		if (check[x - 1] == 0 && x - 1 >= 0 && x - 1 <= 100000) {
			check[x - 1] = check[x] + 1;
			q.push(x - 1);
		}
		if (check[x + 1] == 0 && x + 1 >= 0 && x + 1 <= 100000) {
			check[x + 1] = check[x] + 1;
			q.push(x + 1);
		}
		if (check[x * 2] == 0 && x * 2 >= 0 && x * 2 <= 100000) {
			check[x * 2] = check[x] + 1;
			q.push(x * 2);
		}
	}
}
int main() {
	cin >> n >> k;
	q.push(n);
	bfs();
}