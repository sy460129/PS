#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x, n;
	while (cin >> x) {
		cin >> n;
		bool check = false;
		x *= 10000000;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int f = 0, e = n - 1, c = 0;
		while (1) {
			int mid = (f + e) / 2;
			if (arr[c] + arr[mid] == x) {
				if (c != mid) {
					cout << "yes " << arr[c] << " " << arr[mid] << "\n";
					check = true;
					c = n;
				}
				else {
					f++;
				}
			}
			else if (arr[c] + arr[mid] > x) {
				e = mid - 1;
			}
			else if (arr[c] + arr[mid] < x) {
				f = mid + 1;
			}
			if (f > e) {
				c++;
				f = 0, e = n - 1;
			}
			if (c >= n) {
				if (!check) {
					cout << "danger\n";
				}
				break;
			}
		}
	}
}