#include <iostream>
#include <cmath>
using namespace std;
using ll=long long;
ll dp[2000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, t; cin >> n;
	ll ans=n, cnt;
	for(int i=0; i<n; i++){
		cin >> t;
		dp[t]++;
	}
	for(int i=1; i<2000001; i++){
		cnt=0;
		for(int j=i; j<2000001; j+=i){
			cnt+=dp[j];
		}
		if(cnt>1) ans=max(ans, cnt*i);
	}
	cout << ans;
}