#include <iostream>
using namespace std;
int dp[100001];
int main(){
	int n, x, ans=-2147483647; cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		i==0 ? dp[i]=x : dp[i]=max(x, dp[i-1]+x);
		ans=max(ans, dp[i]);
	}
	cout << ans;
}