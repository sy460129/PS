#include <iostream>
using namespace std;
int dp[31];
int main(){
	int n; cin >> n;
	dp[0]=1, dp[2]=3;
	for(int i=4; i<=n; i+=2) dp[i]=dp[i-2]*4-dp[i-4];
	cout << dp[n];
}