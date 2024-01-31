#include <iostream>
using namespace std;
int dp[16];
int main() {
	int t, c, v, l; cin >> t;
	dp[1]=1, dp[2]=2;
	for(int i=3; i<16; i++) dp[i]=dp[i-1]+dp[i-2];
	for(int i=1; i<=t; i++){
		cin >> c >> v >> l;
		cout << "Case #" << i << ": " << dp[l] << "\n";
	}
}