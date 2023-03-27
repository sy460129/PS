#include <iostream>
using namespace std;
int arr[201];
int brr[1001];
int find(int x) {
	if (arr[x] == x) {
		return x;
	}
	else {
		return arr[x] = find(arr[x]);
	}
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		a > b ? arr[a] = b : arr[b] = a;
	}
}
int main() {
	int n, m, t;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> t;
			if (t == 1) {
				uni(i, j);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> brr[i];
	}
	for (int i = 1; i < m; i++) {
		if (arr[brr[i]] != arr[brr[i - 1]]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}