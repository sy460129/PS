#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, res = 2147483647;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n/2; i++) {
		res = min(res, arr[i] + arr[n - i - 1]);
	}
	cout << res << "\n";
}