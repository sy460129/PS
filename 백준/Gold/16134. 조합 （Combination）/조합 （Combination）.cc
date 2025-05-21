#include <iostream>
#define MOD 1000000007
using namespace std;
using ull=unsigned long long;
ull dp[1000001];
ull mul(ull x, int m){
	if(!m) return 1;
	else if(m==1) return x;
	if(m%2) return x*mul(x, m-1)%MOD;
	ull h=mul(x, m/2)%MOD;
	return h*h%MOD;
}
int main(){
	int n, r; cin >> n >> r;
	dp[0]=1;
	for(int i=1; i<=n; i++) dp[i]=(dp[i-1]*i)%MOD;
	cout << dp[n]*mul((dp[n-r])*dp[r]%MOD, MOD-2)%MOD;
}