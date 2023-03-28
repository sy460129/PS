#include<iostream>
#include<deque>
#include<queue>
using namespace std;
int arr[101][101];
bool check[101][101];
int n, a, turn, x, y;
char c;
deque<pair<int, int>>d;
queue<pair<int, char>>q;
int main() {
	int cnt = 0, i = 1, j = 1, t = 0;
	cin >> n >> a;
	while(a--) {
		cin >> x >> y;
		arr[x][y] = 1;
	}
	cin >> turn;
	while (turn--) {
		cin >> x >> c;
		q.push({ x,c });
	}
	d.push_back({ 1,1 });
	check[1][1] = true;
	while (1) {
		if (!q.empty() && cnt == q.front().first) {
			if (q.front().second == 'D') {
				t += 1;
				if (t > 3) {
					t = 0;
				}
			}
			else {
				t -= 1;
				if (t < 0) {
					t = 3;
				}
			}
			q.pop();
		}
		if (t % 4 == 0) {
			j++;
			if (check[i][j] == true || j > n) {
				break;
			}
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
				d.push_back({ i,j });
				check[i][j] = true;
			}
			else {
				d.push_back({ i,j });
				check[i][j] = true;
				check[d.front().first][d.front().second] = false;
				d.pop_front();
			}
		}
		else if (t % 4 == 1) {
			i++;
			if (check[i][j] == true || i > n) {
				break;
			}
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
				d.push_back({ i,j });
				check[i][j] = true;
			}
			else {
				d.push_back({ i,j });
				check[i][j] = true;
				check[d.front().first][d.front().second] = false;
				d.pop_front();
			}
		}
		else if (t % 4 == 2) {
			j--;
			if (check[i][j] == true || j < 1) {
				break;
			}
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
				d.push_back({ i,j });
				check[i][j] = true;
			}
			else {
				d.push_back({ i,j });
				check[i][j] = true;
				check[d.front().first][d.front().second] = false;
				d.pop_front();
			}
		}
		else if (t % 4 == 3) {
			i--;
			if (check[i][j] == true || i < 1) {
				break;
			}
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
				d.push_back({ i,j });
				check[i][j] = true;
			}
			else {
				d.push_back({ i,j });
				check[i][j] = true;
				check[d.front().first][d.front().second] = false;
				d.pop_front();
			}
		}
		cnt++;
	}
	cout << cnt + 1;
}