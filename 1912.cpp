#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = arr[0];
	for (int i = 1; i < n; i++) {
		arr[i] = max(arr[i], arr[i] + arr[i - 1]);
		sum = max(sum, arr[i]);
	}
	cout << sum << "\n";
}