#include <iostream>
using namespace std;
int dp[100001];
int main(){
	int n, ans; cin >> n;
	for(int i=0; i<n; i++){
		cin >> dp[i];
		i==0 ? ans=dp[i] : dp[i]=max(dp[i], dp[i-1]+dp[i]);
		ans=max(ans, dp[i]);
	}
	cout << ans;
}