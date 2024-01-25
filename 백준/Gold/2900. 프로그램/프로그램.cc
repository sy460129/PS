#include <iostream>
#include <set>
#define MAX 1000001
using namespace std;
using ll=long long;
ll dp[MAX];
ll cnt[MAX];
set<int>s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k, x, l, r; cin >> n >> k;
	while(k--){
		cin >> x;
		s.insert(x);
		cnt[x]++;
	}
	for(auto e : s){
		for(int i=1; i<=MAX; i+=e) dp[i-1]+=cnt[e];
	}
	for(int i=1; i<MAX; i++) dp[i]+=dp[i-1];
	cin >> x;
	while(x--){
		cin >> l >> r;
		cout << dp[r]-dp[l-1] << "\n";
	}
}