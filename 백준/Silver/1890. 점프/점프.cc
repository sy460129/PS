#include <iostream>
using namespace std;
int arr[101][101];
long long dp[101][101];
int n;
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	dp[0][0]=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!dp[i][j] || !arr[i][j]) continue;
			int nx=i+arr[i][j];
			int ny=j+arr[i][j];
			if(nx<n) dp[nx][j]+=dp[i][j];
			if(ny<n) dp[i][ny]+=dp[i][j];
		}
	}
	cout << dp[n-1][n-1];
}