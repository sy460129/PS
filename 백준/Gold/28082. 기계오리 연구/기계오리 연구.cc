#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int dp[50001];
int arr[501];
bool cmp(int a, int b) {return a>b;}
int main() {
	int n, k, cnt=0; cin >> n >> k;
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n, cmp);
	fill(dp, dp+50001, 501);
	for(int i=0; i<n; i++){
		for(int j=50000; j>=1; j--){
			if(j<arr[i]) break;
			if(dp[j-arr[i]] && dp[j-arr[i]]<k) dp[j]=min(dp[j], dp[j-arr[i]]+1);
		}
		dp[arr[i]]=1;
	}
	for(int i=1; i<=50000; i++){
		if(dp[i] && dp[i]<=k) cnt++;
	}
	cout << cnt << "\n";
	for(int i=1; i<=50000; i++){
		if(dp[i] && dp[i]<=k) cout << i << " ";
	}
}