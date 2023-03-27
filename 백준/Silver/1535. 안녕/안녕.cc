#include <iostream>
using namespace std;
int v[21], w[21];
int dp[21][101];
int main(){
	int n, ans=0; cin >> n;
	for(int i=1; i<=n; i++) cin >> w[i];
	for(int i=1; i<=n; i++) cin >> v[i];
	for(int i=1; i<=n; i++){
		for(int j=0; j<100; j++){
			if(w[i]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j], v[i]+dp[i-1][j-w[i]]);
			ans=max(ans, dp[i][j]);
		}
	}
	cout << ans;
}