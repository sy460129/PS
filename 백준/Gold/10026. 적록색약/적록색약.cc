#include<iostream>
#include<vector>
using namespace std;
string arr[101][101];
bool check[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, cnt = 0, cntt = 0;
void dfsr(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>n || ny>n) {
			continue;
		}
		if (arr[nx][ny] == "R" && check[nx][ny] == false) {
			dfsr(nx, ny);
		}
	}
}
void dfsg(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>n || ny>n) {
			continue;
		}
		if (arr[nx][ny] == "G" && check[nx][ny] == false) {
			dfsg(nx, ny);
		}
	}
}
void dfsb(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>n || ny>n) {
			continue;
		}
		if (arr[nx][ny] == "B" && check[nx][ny] == false) {
			dfsb(nx, ny);
		}
	}
}
int main() {
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == "R" && check[i][j] == false) {
				dfsr(i, j);
				cnt++;
			}
			else if(arr[i][j] == "G" && check[i][j] == false) {
				dfsg(i, j);
				cnt++;
			}
			else if (arr[i][j] == "B" && check[i][j] == false) {
				dfsb(i, j);
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == "R") {
				arr[i][j] = "G";
			}
			check[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == "G" && check[i][j] == false) {
				dfsg(i, j);
				cntt++;
			}
			else if (arr[i][j] == "B" && check[i][j] == false) {
				dfsb(i, j);
				cntt++;
			}
		}
	}
	cout << cnt << " " << cntt;
}