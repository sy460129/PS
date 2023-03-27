#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, x, res = 2147483647;
	cin >> n >> x;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int f = 0, e = 0, c = 0;
	while (1) {
		if (res == x) {
			break;
		}
		if (c >= x) {
			res = min(res, c);
			if (f == e) {
				e++;
			}
			else {
				f++;
			}
			if (e == n) {
				break;
			}
			else {
				c = arr[e] - arr[f];
			}
		}
		else {
			e++;
			if (e == n) {
				break;
			}
			c = arr[e] - arr[f];
		}
	}
	cout << res;
}