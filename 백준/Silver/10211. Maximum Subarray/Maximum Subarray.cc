#include<iostream>
using namespace std;
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int res = arr[0];
		for (int i = 1; i < n; i++) {
			arr[i] = max(arr[i], arr[i] + arr[i - 1]);
			res = max(arr[i], res);
		}
		cout << res << "\n";
	}
}