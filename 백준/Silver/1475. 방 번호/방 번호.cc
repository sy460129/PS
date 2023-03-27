#include<iostream>
using namespace std;
int arr[10];
int main() {
	int n, x, res = 1;
	cin >> n;
	while (n != 0) {
		x = n % 10;
		n /= 10;
		arr[x]++;
	}
	if ((arr[6] + arr[9]) % 2 != 0) {
		arr[6] = (arr[6] + arr[9])/2 + 1;
	}
	else {
		arr[6] = (arr[6] + arr[9]) / 2;
	}
	for (int i = 0; i < 9; i++) {
		res = max(res, arr[i]);
	}
	cout << res;
}