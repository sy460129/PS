#include <iostream>
using namespace std;
using ll=long long;
ll dp[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll t, x, n; cin >> t;
	dp[1]=1, dp[2]=1;
	for(int i=1; i<=t; i++){
		cin >> n >> x;
		for(int i=3; i<=n; i++) dp[i]=(dp[i-1]+dp[i-2])%x;
		cout << "Case #" << i << ": " << dp[n]%x << "\n";
	}
}