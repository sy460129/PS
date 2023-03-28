#include<iostream>
int arr[1001];
using namespace std;
int main() {
	int n;
	cin >> n;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	cout << arr[n];
}