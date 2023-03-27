#include<iostream>
#include<algorithm>
using namespace std;
int compare(int a, int b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, r = 0;
	cin >> n;
	int* A = new int[n];
	int* B = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	sort(A, A + n);
	sort(B, B + n, compare);
	for (int i = 0; i < n; i++) {
		r += A[i] * B[i];
	}
	cout << r << "\n";
}