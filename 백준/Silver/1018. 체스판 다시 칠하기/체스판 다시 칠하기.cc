#include<iostream>
using namespace std;
char arr[51][51];
string b = "BWBWBWBW";
string w = "WBWBWBWB";
int main() {
	int n, m, sum = 2147483647;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int cnt = 0, res = 0;
			for (int x = i; x < 8 + i; x++) {
				for (int y = j; y < 8 + j; y++) {
					if (cnt % 2 == 0) {
						if (arr[x][y] != b[y - j]) {
							res++;
						}
					}
					else {
						if (arr[x][y] != w[y - j]) {
							res++;
						}
					}
				}
				cnt++;
			}
			sum = min(sum, res);
		}
	}
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int cnt = 0, res = 0;
			for (int x = i; x < 8 + i; x++) {
				for (int y = j; y < 8 + j; y++) {
					if (cnt % 2 == 0) {
						if (arr[x][y] != w[y - j]) {
							res++;
						}
					}
					else {
						if (arr[x][y] != b[y - j]) {
							res++;
						}
					}
				}
				cnt++;
			}
			sum = min(sum, res);
		}
	}
	cout << sum << "\n";
}