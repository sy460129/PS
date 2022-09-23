#include <iostream>
#include <queue>
using namespace std;
int F, S, G, U, D;
int check[1000001];
queue<int> q;
int bfs() {
	q.push(S);
	while (!q.empty()) {
		int x=q.front(); q.pop();
		if(x==G) return check[x];
		if (x+U<=F){
			if (check[x+U]==0) check[x+U]=check[x]+1, q.push(x+U);	
		}
		if(x-D>=1){
			if(check[x-D]==0) check[x-D]=check[x]+1, q.push(x-D);
		}
    }
	return -1;
}
int main() {
	cin >> F >> S >> G >> U >> D;
	check[S]=1;
	int res=bfs();
    res==-1 ? cout << "use the stairs" : cout << res-1;
}