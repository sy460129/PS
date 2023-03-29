#include <iostream>
using namespace std;
using ll=long long;
ll dp[81];
int main(){
	int n; cin >> n;
    dp[1]=1, dp[2]=1;
    for(int i=3; i<=n; i++) dp[i]=dp[i-1]+dp[i-2];
    cout << dp[n]*4+dp[n-1]*2;
}