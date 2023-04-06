#include<iostream>
using namespace std;
int main() {
	int p[30][30];
	int n, k;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				p[i][j] = 1;
			}
			else {
				p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
			}
		}
	}
	cin >> n >> k;
	cout << p[n-1][k-1] << "\n";
}