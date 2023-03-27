#include<iostream>
#include<vector>
using namespace std;
int arr[1001][1001];
int main() {
	int n, m, t = 0;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
			if (arr[i][j] == 1) {
				t = 1;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (arr[i][j] != 0 && arr[i - 1][j] != 0 && arr[i][j - 1] != 0 && arr[i - 1][j - 1] != 0) {
				arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
				t = max(t, arr[i][j]);
			}
		}
	}
	cout << t * t;
}