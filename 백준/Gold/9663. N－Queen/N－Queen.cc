#include<iostream>
using namespace std;
int col[15];
int n, total = 0;
bool check(int lev) {
	for (int i = 0; i < lev; i++) {
		if (col[i] == col[lev] || abs(col[i]-col[lev]) == lev - i) {
			return false;
		}
	}
	return true;
}
void nqueen(int x) {
	if (n == x) {
		total++;
	}
	else {
		for (int i = 0; i < n; i++) {
			col[x] = i;
			if (check(x)) {
				nqueen(x + 1);
			}
		}
	}
}
int main() {
	cin >> n;
	nqueen(0);
	cout << total;
}