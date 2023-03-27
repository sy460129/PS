#include<iostream>
#include<algorithm>
using namespace std;
int arr[10];
int main() {
	int sum = 0, x = 0, y = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				x = arr[i];
				y = arr[j];
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (arr[i] == x || arr[i] == y) {
			continue;
		}
		else {
			cout << arr[i] << "\n";
		}
	}
}