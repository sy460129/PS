#include <iostream>
#include <algorithm>
using namespace std;
int dp[5001], ans[5001];
int main(){
	int n, cnt=0; cin >> n;
	for(int i=0; i<n; i++) cin >> dp[i];
	sort(dp, dp+n);
	fill(ans, ans+n, 1);
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(!(dp[i]%dp[j])) ans[i]=max(ans[i], ans[j]+1);
		}
	}
	for(int i=0; i<n; i++) cnt=max(cnt,ans[i]);
	cout << n-cnt;
}