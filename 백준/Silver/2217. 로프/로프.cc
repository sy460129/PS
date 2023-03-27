#include<iostream>
#include<algorithm>
using namespace std;
int cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, sum, res = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		sum = arr[i] * (i + 1);
		res = max(res, sum);
	}
	cout << res;
}