#include <iostream>
using namespace std;
int dp[201][201];
int main(){
	int n, k; cin >> n >> k;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			if(i==1) dp[j][i]=1;
			else if(j==1) dp[j][i]=i;
			else dp[j][i]=(dp[j][i-1]+dp[j-1][i])%1000000000;
		}
	}
	cout << dp[n][k];
}