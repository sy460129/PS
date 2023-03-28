#include<iostream>
using namespace std;
int LCS[1001];
int N[1001];
int main() {
	int n, t = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> N[i];
		int j = 0;
		for (int k = 0; k < i; k++) {
			if (N[i] < N[k]) {
				j = max(j, LCS[k]);
			}
		}
		LCS[i] = j + 1;
		t = max(t, LCS[i]);
	}
	cout << t;
}