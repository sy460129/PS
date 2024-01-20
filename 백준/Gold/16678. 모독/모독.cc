#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001];
int main(){
	long long ans=0;
	int n; cin >> n;
	for(int i=1; i<=n; i++) cin >> dp[i];
	sort(dp, dp+n+1);
	for(int i=1; i<=n; i++){
		if(dp[i]>dp[i-1]+1) {
			ans+=dp[i]-dp[i-1]-1;
			dp[i]=dp[i-1]+1;
		}
	}
	cout << ans;
}