#include <iostream>
using namespace std;
int arr[1001][3];
int dp[1001][3];
int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		if(i==0){
			dp[i][0]=arr[i][0];
			dp[i][1]=arr[i][1];
			dp[i][2]=arr[i][2];
		}
		else{
			dp[i][0]=min(dp[i-1][1], dp[i-1][2])+arr[i][0];
			dp[i][1]=min(dp[i-1][0], dp[i-1][2])+arr[i][1];
			dp[i][2]=min(dp[i-1][0], dp[i-1][1])+arr[i][2];
		}
	}
	cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}