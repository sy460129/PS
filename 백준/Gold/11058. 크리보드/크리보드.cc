#include <iostream>
using namespace std;
long long dp[101];
int main() {
	int n;
	cin >> n;
	for(int i=1; i<=6; i++){
		dp[i]=i;
	}
	for(int i=6; i<=n; i++){
		dp[i]=max(max(dp[i-3]*2, dp[i-4]*3),dp[i-5]*4);
	}
	cout << dp[n];
}