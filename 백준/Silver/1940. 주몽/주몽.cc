#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int f = 0, e = n - 1;
	while (f < e) {
		if (arr[f] + arr[e] >= m) {
			if (arr[f] + arr[e] == m) {
				f++, e--;
				cnt++;
			}
			else {
				e--;
			}
		}
		else {
			f++;
		}
	}
	cout << cnt << "\n";
}