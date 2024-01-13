#include <iostream>
#include <map>
using namespace std;
map<int,int>b, t;
int dp[500001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k, x, ansb, anst, ans=500001, cnt=1; cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> x;
		i%2 ? t[x]++ : b[x]++;
	}
	ansb=anst=n/2;
	for(int i=1; i<=k; i++){
		dp[i]+=ansb;
		dp[k-i+1]+=anst;
		ansb-=b[i];
		anst-=t[i];
	}
	for(int i=1; i<=k; i++){
		if(i==1) ans=dp[i];
		else{
			if(ans==dp[i]) cnt++;
			else if(ans>dp[i]) ans=dp[i], cnt=1;
		}
	}
	cout << ans << " " << cnt;
}