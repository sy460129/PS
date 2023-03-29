#include <iostream>
#define MAX 1000000007
using namespace std;
int dp[1001][1001];
int main(){
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(i==1 || j==1) dp[i][j]=1;
			else dp[i][j]=((dp[i-1][j]+dp[i][j-1])%MAX+dp[i-1][j-1])%MAX;
		}
	}
	cout << dp[n][m];
}