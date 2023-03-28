#include <iostream>
#define num 1000000
#define MAX 1500000
using namespace std;
using ll=long long;
int dp[MAX];
int main() {
	ll n; cin >> n;
	dp[0]=0, dp[1]=1;
	for(int i=2; i<=MAX; i++) dp[i]=(dp[i-1]+dp[i-2])%num;
	cout << dp[n%MAX];
}