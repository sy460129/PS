#include <iostream>
using namespace std;
int arr[21], brr[21], dp[21][2];
int n, m, k;
int main() {
	cin >> n;
	for(int i=1; i<n; i++){
		cin >> arr[i] >> brr[i];
	}
	cin >> k;
	dp[2][0]=arr[1];
	dp[2][1]=arr[1];
	dp[3][0]=min(dp[2][0]+arr[2], dp[1][0]+brr[1]);
	dp[3][1]=dp[3][0];
	for(int i=4; i<=n; i++){
		dp[i][0]=min(dp[i-1][0]+arr[i-1], dp[i-2][0]+brr[i-2]);
		dp[i][1]=min(dp[i-3][0]+k, min(dp[i-1][1]+arr[i-1], dp[i-2][1]+brr[i-2]));
		
	}
	cout << min(dp[n][0], dp[n][1]);
}