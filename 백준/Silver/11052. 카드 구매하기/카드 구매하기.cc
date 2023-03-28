#include <iostream>
using namespace std;
int dp[1002];
int card[1002];
int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> card[i];
	}
	for(int i=1; i<=n; i++){
		dp[i]=card[i];
		for(int j=1; j<i; j++){
			dp[i]=max(dp[i], dp[j]+card[i-j]);
		}
	}
	cout << dp[n];
}