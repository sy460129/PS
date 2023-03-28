#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	sort(arr, arr + n);
	int f = 0, c = 0, e = n - 1, cnt = 0;
	while (1) {
		int mid = (f + e) / 2;
		if (arr[c] + arr[mid] > m) {
			e = mid - 1;
		}
		else if (arr[c] + arr[mid] < m) {
			f = mid + 1;
		}
		if (arr[c] + arr[mid] == m) {
			if (c != mid) {
				cnt++;
				c++;
				f = 0, e = n - 1;
			}
			else {
				f = mid + 1;
			}
		}
		if (f > e) {
			f = 0, e = n - 1, c++;
		}
		if (c == n) {
			break;
		}
	}
	cout << cnt / 2 << "\n";
}