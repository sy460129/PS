#include <iostream>
#include <cstring>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int arr[51][51];
int dp[51][51];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n, m, ans;
bool visit[51][51];
int dfs(int x, int y){
	if(visit[x][y]){
		cout << -1;
		exit(0);
	}
	if(!dp[x][y]){
		visit[x][y]=true;
		dp[x][y]=1;
		rep(i, 0, 4){
			int nx=x+dx[i]*arr[x][y];
			int ny=y+dy[i]*arr[x][y];
			if(nx<0 || ny<0 || nx>n-1 || ny>m-1 || !arr[nx][ny]) continue;
			dp[x][y]=max(dp[x][y], dfs(nx,ny)+1);
		}
		visit[x][y]=false;
	}
	return dp[x][y];
}
int main(){
	string s;
	cin >> n >> m;
	rep(i, 0, n){
		cin >> s;
		rep(j, 0, m){
			s[j]!='H' ? arr[i][j]=s[j]-'0' : arr[i][j]=0;
		}
	}
	cout << dfs(0, 0);
}