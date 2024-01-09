#include <iostream>
using namespace std;
int dp[1000001];
int main() {
    int n, cnt=0, ans=0, x; cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        dp[x]=dp[x-1]+1;
        ans=max(ans, dp[x]);
    }
    cout << n-ans;
}