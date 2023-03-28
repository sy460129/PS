#include <iostream>
using namespace std;
using ll=long long;
int dp[500001];
int main() {
	ll t, x, y; cin >> t;
	while(t--){
		cin >> x >> y;
		dp[0]=1, dp[1]=1;
		for(ll i=2; i<=y*y-1; i++){
			dp[i]=(dp[i-1]%y+dp[i-2]%y)%y;
			if(dp[i]==1 && dp[i-1]==0){
				cout << x << " " << i << "\n";
				break;
			}
		}
		fill(dp, dp+500001, 0);
	}
}