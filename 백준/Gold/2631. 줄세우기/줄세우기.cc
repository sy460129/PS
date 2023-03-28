#include<iostream>
using namespace std;
int LCS[201];
int main() {
	int n, t = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int j = 0;
		for (int k = 0; k < i; k++) {
			if (arr[i] > arr[k]) {
				j = max(j, LCS[k]);
			}
		}
		LCS[i] = j + 1;
		t = max(t, LCS[i]);
	}
	cout << n - t << "\n";
}