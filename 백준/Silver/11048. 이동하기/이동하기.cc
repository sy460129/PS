#include <iostream>
using namespace std;
int dp[1001][1001];
int arr[1001][1001];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
			if(j==0){
				i==0 ? dp[i][j]=arr[i][j] : dp[i][j]=arr[i][j]+dp[i-1][j];
			}
			if(i==0){
				j==0 ? dp[i][j]=arr[i][j] : dp[i][j]=arr[i][j]+dp[i][j-1];
			}
		}
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			dp[i][j]=max(dp[i-1][j], dp[i][j-1])+arr[i][j];
		}
	}
	cout << dp[n-1][m-1];
}