#include <iostream>
using namespace std;
int arr[501][501];
int dp[501][501];
int main(){
	int n, m, ans=0; cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> arr[i][j];
	}
	for(int i=0; i<m; i++) dp[0][i]=arr[0][i];
	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++){
			dp[i][j]=dp[i-1][j]+arr[i][j];
			if(j!=0) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+arr[i][j]);
			if(j!=m-1) dp[i][j]=max(dp[i][j], dp[i-1][j+1]+arr[i][j]);
		}
	}
	for(int i=0; i<m; i++) ans=max(ans, dp[n-1][i]);
	cout << ans;
}