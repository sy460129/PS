#include <iostream>
#include <map>
using namespace std;
using ll=long long;
map<ll, ll>dp;
ll div(ll x, ll p, ll q) {
	if(dp[x]) return dp[x];
	else return dp[x]=div(x/p, p, q)+div(x/q, p, q);
}
int main(){
	ll n, p, q, ans=0; cin >> n >> p >> q;
	dp[0]=1;
	ans=div(n/p, p, q)+div(n/q, p, q);
	if(!n) ans=1;
	cout << ans;
}