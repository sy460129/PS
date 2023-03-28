#include <iostream>
#include <queue>
#include<cstring>
using namespace std;
int F, S, G, U, D;
int check[1000001];
queue<int> q;
int bfs() {
	q.push(S);
	check[S] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == G) {
			return check[x];
		}
		if (x + U >= 1 && x + U <= F) {
			if (check[x + U] == -1) {
				check[x + U] = check[x] + 1;
				q.push(x + U);
			}
		}

		if (x - D >= 1 && x - D <= F) {
			if (check[x - D] == -1) {
				check[x - D] = check[x] + 1;
				q.push(x - D);
			}
		}
	}
	return -1;
}
int main() {
	cin >> F >> S >> G >> U >> D;
	memset(check, -1, sizeof(check));
	int res = bfs();
	if (res == -1) {
		cout << "use the stairs\n";
	}
	else {
		cout << res << '\n';
	}
}