#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = n - 1; i >= 2; i--) {
		if (arr[i] < arr[i - 1] + arr[i - 2]) {
			cout << arr[i] + arr[i - 1] + arr[i - 2];
			return 0;
		}
	}
	cout << -1;
}