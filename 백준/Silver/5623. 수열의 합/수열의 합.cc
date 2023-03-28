#include <iostream>
using namespace std;
int arr[1002][1002];
int dp[1002];
bool c;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> arr[i][j];
		}
	}
	for(int i=1; i<=100000; i++){
		c=true;
		dp[1]=i;
		for(int j=2; j<=n; j++){
			dp[j]=arr[1][j]-dp[1];
		}
		for(int j=1; j<=n; j++){
			if(j==2 || !c) continue;
			if(dp[2]+dp[j]!=arr[2][j]) c=false;
		}
		if(c) break;
	}
	for(int i=1; i<=n; i++){
		cout << dp[i] << " ";
	}
}