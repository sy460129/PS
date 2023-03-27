#include<iostream>
using namespace std;
int ans[51];
int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		double a = -1000000000;
		for (int j = i + 1; j < n; j++) {
			double b = (double)(arr[j] - arr[i]) / (double)(j - i);
			if (b > a) {
				ans[i]++;
				a = b;
			}
		}
	}
	for (int i = n - 1; i > 0; i--) {
		double a = -1000000000;
		for (int j = i - 1; j >=0; j--) {
			double b = (double)(arr[j] - arr[i]) / (double)(i - j);
			if (b > a) {
				ans[i]++;
				a = b;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, ans[i]);
	}
	cout << res;
}