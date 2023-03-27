#include <iostream>
using namespace std;
int n, m, k, cnt;
char arr[5][5];
bool visit[5][5];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void dfs(int x, int y, int t){
	if(t==k){
		if(x==0 && y==m-1) cnt++;
		return;
	}
	bool check[5][5];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			check[i][j]=visit[i][j];
		}
	}
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || ny<0 || nx>n-1 || ny>m-1 || arr[nx][ny]=='T' || check[nx][ny]) continue;
		else{
			visit[nx][ny]=true;
			dfs(nx,ny,t+1);
			visit[nx][ny]=false;
		}
	}
}
int main(){
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	visit[n-1][0]=true;
	dfs(n-1,0,1);
	cout << cnt;
}