#include<iostream>
using namespace std;
int sum, n, k, cnt = 0;
int arr[21];
bool visit[21];
void dfs(int num) {
	if (sum == k) {
		cnt++;
	}
	for (int i = num + 1; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			sum += arr[i];
			dfs(i);
			visit[i] = false;
			sum -= arr[i];
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		sum = arr[i];
		visit[i] = true;
		dfs(i);
		visit[i] = false;
	}
	cout << cnt;
}