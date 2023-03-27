#include<iostream>
#include<vector>
using namespace std;
int arr[10][10];
vector<pair<int, int>>v;
bool check(int n, int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (arr[x][i] == n || arr[i][y] == n) {
			return false;
		}
	}
	int nx = (x / 3) * 3, ny = (y / 3) * 3;
	for (int i = nx; i < nx + 3; i++) {
		for (int j = ny; j < ny + 3; j++) {
			if (n == arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void sudoku(int n) {
	if (n == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}
	int x = v[n].first, y = v[n].second;
	for (int i = 1; i <= 9; i++) {
		if (check(i, x, y)) {
			arr[x][y] = i;
			sudoku(n + 1);
		}
	}
	arr[x][y] = 0;
	return;
}
int main() {
	string s;
	for (int i = 0; i < 9; i++) {
		cin >> s;
		for (int j = 0; j < 9; j++) {
			arr[i][j] = s[j] - '0';
			if (arr[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	sudoku(0);
}