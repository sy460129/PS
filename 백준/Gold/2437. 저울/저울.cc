#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, sum = 0, c = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	if (arr[0] != 1) {
		cout << 1 << "\n";
		return 0;
	}
	for (int i = 0; i < n-1; i++) {
		sum += arr[i];
		if (sum < arr[i + 1] && sum+1 !=arr[i+1]) {
			c = 1;
			break;
		}
	}
	if (c == 0) {
		sum += arr[n - 1];
	}
	cout << sum + 1 << "\n";
}