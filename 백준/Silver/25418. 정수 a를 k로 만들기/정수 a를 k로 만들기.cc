#include <iostream>
#include <queue>
#define MAX 1000000
using namespace std;
int check[MAX+1];
queue<int>q;
int n, k;
void bfs(){
	while(!q.empty()){
		int x=q.front(); q.pop();
		if(x==k){
			cout << check[x];
			exit(0);
		}
		if(x+1<=MAX && !check[x+1]) q.push(x+1), check[x+1]=check[x]+1;
		if(2*x<=MAX && !check[2*x]) q.push(2*x), check[2*x]=check[x]+1;
	}
}
int main(){
	cin >> n >> k;
	q.push(n);
	bfs();
}