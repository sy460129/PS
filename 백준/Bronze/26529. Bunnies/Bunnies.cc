#include <iostream>
using namespace std;
int dp[46];
int main(){
	int n, x; cin >> n;
	dp[0]=1, dp[1]=1;
	for(int i=2; i<=45; i++) dp[i]=dp[i-1]+dp[i-2];
	while(n--){
		cin >> x; cout << dp[x] << "\n";
	}
}