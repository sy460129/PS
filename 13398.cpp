#include <iostream>
using namespace std;
int dp[100001];
int arr[100001];
int main(){
	int n, x, ans=-1001; cin >> n;
	cin >> arr[0];
	dp[0]=arr[0];
	ans=arr[0];
	for(int i=1; i<n; i++){
		cin >> x;
		arr[i]=max(x, arr[i-1]+x);
		dp[i]=max(arr[i-1], dp[i-1]+x);
		ans=max(ans, max(dp[i], arr[i]));
	}
	cout << ans;
}