#include <iostream>
using namespace std;
int sum[1000001], cnt[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long ans=0;
	int n, m, t; cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> t;
		sum[i]=sum[i-1]+t%m;
	}
	for(int i=1; i<=n; i++){
		t=sum[i]%m;
		ans+=cnt[t]++;
		if(!t) ans++;
	}
	cout << ans;
}