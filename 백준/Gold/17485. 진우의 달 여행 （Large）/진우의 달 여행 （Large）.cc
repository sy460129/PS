#include <iostream>
using namespace std;
int dp[1011][1011][3], arr[1001][1001];
int main(){
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m+1; j++){
			for(int k=0; k<3; k++){
				if(i==1 && j!=0 && j!=m+1) dp[i][j][k]=arr[i][j];
				else dp[i][j][k]=666666;
			}
		}
	}
	for(int i=2; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=0; k<3; k++){
				if(k==0){
					dp[i][j][k]=min(dp[i-1][j-1][2],dp[i-1][j][1])+arr[i][j];
				}
				else if(k==1) {
					dp[i][j][k]=min(dp[i-1][j-1][2],dp[i-1][j+1][0])+arr[i][j];
				}
				else{
					dp[i][j][k]=min(dp[i-1][j][1],dp[i-1][j+1][0])+arr[i][j];
				}
			}
		}
	}
	int ans=6666666;
	for(int j=1; j<=m; j++){
		for(int k=0; k<3; k++){
			ans=min(ans,dp[n][j][k]);
		}
	}
	cout << ans;
}