#include <iostream>
using namespace std;
using ll=long long;
ll dp[1000001], sum[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n, h, ans=0; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> dp[i];
		sum[i]+=sum[i-1]+dp[i];
	}
	for(int i=1; i<n-1; i++){
		h=sum[i];
		ll f=i+1, e=n-1, m, idx;
		m=(f+e)/2;
		while(f<=e){
			if(sum[n]-sum[m]>h) f=m+1;
			else e=m-1;
			m=(f+e)/2;
		}
		if(sum[m]-sum[i]<=sum[n]-sum[m]) continue;
		idx=m;
		f=i+1, e=n-1;
		while(f<=e){
			if(sum[m]-sum[i]>sum[n]-sum[m]) e=m-1;
			else f=m+1;
			m=(f+e)/2;
		}
		ans+=idx-m;
	}
	cout << ans;
}