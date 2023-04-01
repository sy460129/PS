#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int* arr = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	int s = arr[0], c = 0, t = 0, sum = 0;
	for (int i = 1; i < m; i++) {
		if (arr[i] < s) {
			c++;
			t += arr[i];
		}
		if (arr[i] >= s) {
			sum += s * c - t;
			c = 0, t = 0;
			s = arr[i];
		}
	}
	s = arr[m - 1], c = 0, t = 0;
	for (int i = m - 2; i >= 0; i--) {
		if (arr[i] < s) {
			c++;
			t += arr[i];
		}
		if (arr[i] > s) {
			sum += s * c - t;
			c = 0, t = 0;
			s = arr[i];
		}
	}
	cout << sum << "\n";
}