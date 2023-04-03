#include <iostream>
using namespace std;
#define MAX 2500001
int dp[5001][10][10][10];
int main(){
	int n, x, ans=MAX; cin >> n;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=9; j++){
			for(int k=0; k<=9; k++){
				for(int l=0; l<=9; l++){
					dp[i][j][k][l]=MAX;
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		cin >> x;
		if(i==1){
			dp[1][x][0][0]=min(x,10-x);
			dp[1][0][x][0]=min(x,10-x);
			dp[1][0][0][x]=min(x,10-x);
			continue;
		}
		for(int j=0; j<=9; j++){
			for(int k=0; k<=9; k++){
				for(int l=0; l<=9; l++){
					dp[i][x][k][l]=min(dp[i][x][k][l],dp[i-1][j][k][l]+min(abs(j-x),10-abs(j-x)));					
					dp[i][j][x][l]=min(dp[i][j][x][l],dp[i-1][j][k][l]+min(abs(k-x),10-abs(k-x)));					
					dp[i][j][k][x]=min(dp[i][j][k][x],dp[i-1][j][k][l]+min(abs(l-x),10-abs(l-x)));
				}
			}
		}
	}
	for(int j=0; j<=9; j++){
		for(int k=0; k<=9; k++){
			for(int l=0; l<=9; l++){
				ans=min(ans,dp[n][j][k][l]);
			}
		}
	}
	cout << ans;
}