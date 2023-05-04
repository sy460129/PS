#include <iostream>
using namespace std;
int main(){
	int t, n, m; cin >> t;
	for(int i=1; i<=t; i++){
		cin >> n >> m;
		int* arr=new int[n];
		int* dp=new int[n];
		fill(dp, dp+n, 0);
		long long cnt=0, cur=0, ans=0;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			if(!dp[arr[i]]) cnt++;
			dp[arr[i]]++;
			while(cnt==m){
				ans+=n-i;
				dp[arr[cur]]--;
				if(!dp[arr[cur]]) cnt--;
				cur++;
			}
		}
		cout << "#" << i << " " << ans << "\n";
	}
}