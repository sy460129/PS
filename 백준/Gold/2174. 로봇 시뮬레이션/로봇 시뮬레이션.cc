#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m, a, b;
int arr[101][101];
int brr[5];
vector<int>v;
vector<pair<int, int>>vec;
queue<pair<int, int>>q;
int main() {
	int x, y;
	char c;
	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> c;
		arr[x][y] = i;
		if (c == 'E') {
			brr[i] = 1;
		}
		else if (c == 'S') {
			brr[i] = 2;
		}
		else if (c == 'W') {
			brr[i] = 3;
		}
		else if (c == 'N') {
			brr[i] = 4;
		}
	}
	while (m--) {
		cin >> x >> c >> y;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				if (arr[i][j] == x) {
					q.push({ i,j });
					break;
				}
			}
			if (!q.empty()) {
				break;
			}
		}
		if (c == 'F') {
			arr[q.front().first][q.front().second] = 0;
			if (brr[x] == 1) {
				while (y--) {
					q.front().first += 1;
					if (arr[q.front().first][q.front().second] != 0) {
						cout << "Robot " << x << " crashes into robot " << arr[q.front().first][q.front().second] << "\n";
						return 0;
					}
					else if (q.front().first > a) {
						cout << "Robot " << x << " crashes into the wall\n";
						return 0;
					}
				}
				arr[q.front().first][q.front().second] = x;
			}
			else if (brr[x] == 2) {
				while (y--) {
					q.front().second -= 1;
					if (arr[q.front().first][q.front().second] != 0) {
						cout << "Robot " << x << " crashes into robot " << arr[q.front().first][q.front().second] << "\n";
						return 0;
					}
					else if (q.front().second < 1) {
						cout << "Robot " << x << " crashes into the wall\n";
						return 0;
					}
				}
				arr[q.front().first][q.front().second] = x;
			}
			else if (brr[x] == 3) {
				while (y--) {
					q.front().first -= 1;
					if (arr[q.front().first][q.front().second] != 0) {
						cout << "Robot " << x << " crashes into robot " << arr[q.front().first][q.front().second] << "\n";
						return 0;
					}
					else if (q.front().first < 1) {
						cout << "Robot " << x << " crashes into the wall\n";
						return 0;
					}
				}
				arr[q.front().first][q.front().second] = x;
			}
			else if (brr[x] == 4) {
				while (y--) {
					q.front().second += 1;
					if (arr[q.front().first][q.front().second] != 0) {
						cout << "Robot " << x << " crashes into robot " << arr[q.front().first][q.front().second] << "\n";
						return 0;
					}
					else if (q.front().second > b) {
						cout << "Robot " << x << " crashes into the wall\n";
						return 0;
					}
				}
				arr[q.front().first][q.front().second] = x;
			}
		}
		else if (c == 'R') {
			while (y--) {
				brr[x] += 1;
				if (brr[x] > 4) {
					brr[x] = 1;
				}
			}
		}
		else if (c == 'L') {
			while (y--) {
				brr[x] -= 1;
				if (brr[x] < 1) {
					brr[x] = 4;
				}
			}
		}
		q.pop();
	}
	cout << "OK\n";
}