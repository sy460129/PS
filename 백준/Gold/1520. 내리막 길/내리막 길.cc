#include <iostream>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int arr[500][500];
int dp[500][500];
int n, m;
int dfs(int x, int y){
    if(x==n-1 && y==m-1) return 1;
    if(dp[x][y]==-1){
        dp[x][y]=0;
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(ny<0 || ny>m-1 || nx<0 || nx>n-1) continue;              
            if(arr[x][y]>arr[nx][ny]) dp[x][y]+=dfs(nx,ny);
        }
    }
    return dp[x][y];
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            dp[i][j]=-1;
        }
    }
    cout << dfs(0,0);
}