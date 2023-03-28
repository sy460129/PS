#include <iostream>
#define rep(i, a, b) for(int i=a; i<=b; i++)
using namespace std;
int dp[1002];
int arr[1002];
int cnt=2147483647;
int main(){
    int n; cin >> n;
    rep(i, 1, n) cin >> arr[i];
    dp[1]=0;
    rep(i, 1, n){
        if(i!=1 && dp[i]==0) continue;
        rep(j, 0, arr[i]){
            if(i+j>=n) cnt=min(cnt, dp[i]);
            else{
                if(dp[i+j]==0) dp[i+j]=dp[i]+1;
            }
        }
    }
    cnt!=2147483647 ? cout << cnt : cout << -1;
}