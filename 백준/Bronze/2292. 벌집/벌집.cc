#include<iostream>
using namespace std;
int arr[100001];
int main() {
	int n;
	cin >> n;
	arr[0] = 1;
	for (int i = 1; i < 100001; i++) {
		arr[i] += arr[i - 1] + 6 * i;
	}
	for (int i = 0; i < 100001; i++) {
		if (arr[i] >= n) {
			cout << i + 1;
			return 0;
		}
	}
}