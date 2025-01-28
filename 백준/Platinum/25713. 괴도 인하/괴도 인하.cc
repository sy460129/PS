#include <iostream>
using namespace std;
int dp[1001][1001], dx[1001][1001], dy[1001][1001];
int main(){
	int n, m, k, sx, sy, ex, ey; cin >> n >> m >> k;
	while(k--){
		cin >> sx >> sy >> ex >> ey;
		for(int i=sx; i<=ex; i++) dx[i][sy]++;
		for(int i=sy; i<=ey; i++) dy[sx][i]++;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(i==1) dp[i][j]=dp[i][j-1]+dx[i][j];
			else if(j==1) dp[i][j]=dp[i-1][j]+dy[i][j];
			else dp[i][j]=min(dp[i-1][j]+dy[i][j], dp[i][j-1]+dx[i][j]);
		}
	}
	cout << dp[n][m] << "\n";
}