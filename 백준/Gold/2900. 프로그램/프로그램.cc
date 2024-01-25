#include <iostream>
#define MAX 1000001
using namespace std;
using ll=long long;
ll dp[MAX];
ll cnt[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k, x, l, r; cin >> n >> k;
	while(k--){
		cin >> x;
		cnt[x]++;
	}
	for(int j=0; j<MAX; j++){
		if(!cnt[j]) continue;
		for(int i=0; i<MAX; i+=j) dp[i]+=cnt[j];
	}
	for(int i=1; i<MAX; i++) dp[i]+=dp[i-1];
	cin >> x;
	while(x--){
		cin >> l >> r;
		cout << dp[r]-dp[l-1] << "\n";
	}
}