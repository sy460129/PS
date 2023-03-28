#include <iostream>
using namespace std;
int dp[8][8];
int main(){
	string c;
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> c;
			if(c[0]=='A') dp[i][j]=1;
			else if(c[0]=='T') dp[i][j]=10;
			else if(c[0]=='J') dp[i][j]=11;
			else if(c[0]=='Q') dp[i][j]=12;
			else if(c[0]=='K') dp[i][j]=13;
			else dp[i][j]=c[0]-'0';
		}
	}
	for(int i=n; i>0; i--){
		for(int j=1; j<=n; j++){
			if(i==n) dp[i][j]+=dp[i][j-1];
			else if(j==1) dp[i][j]+=dp[i+1][j];
			else dp[i][j]+=max(dp[i+1][j], dp[i][j-1]);
		}
	}
	cout << dp[1][n];
}