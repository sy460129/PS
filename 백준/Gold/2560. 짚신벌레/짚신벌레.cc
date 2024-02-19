#include <iostream>
using namespace std;
int dp[1000001];
int main(){
	int a, b, d, n; cin >> a >> b >> d >> n;
	dp[0]=1;
	for(int i=1; i<=n; i++){
		dp[i]=dp[i-1];
		if(i>=a) dp[i]+=dp[i-a];
		if(i>=b) dp[i]-=dp[i-b]+1000;
		dp[i]%=1000;
	}
	cout << (dp[n]-dp[n-d]+1000)%1000;
}