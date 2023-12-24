#include <iostream>
using namespace std;
using ull=unsigned long long;
ull dp[101][21];
int main(){
	int n, x; cin >> n >> x;
	dp[0][x]=1;
	for(int i=1; i<n-1; i++){
		cin >> x;
		for(int j=0; j<21; j++){
			if(dp[i-1][j]){
				if(j-x>=0) dp[i][j-x]+=dp[i-1][j];
				if(j+x<21) dp[i][j+x]+=dp[i-1][j];
			}
		}
	}
	cin >> x;
	cout << dp[n-2][x];
}