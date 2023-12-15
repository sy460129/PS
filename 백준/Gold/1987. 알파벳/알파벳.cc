#include <iostream>
using namespace std;
int r, c, ans;
char arr[21][21];
bool check[26];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void dfs(int x, int y, int cnt) {
	ans=max(ans, cnt);
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0 || ny<0 || nx>r-1 || ny>c-1 || check[arr[nx][ny]-'A']) continue;
		check[arr[nx][ny]-'A']=true;
		dfs(nx,ny,cnt+1);
		check[arr[nx][ny]-'A']=false;
	}
}
int main(){
	cin >> r >> c;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> arr[i][j];
		}
	}
	check[arr[0][0]-'A']=true;
	dfs(0,0,1);
	cout << ans;
}