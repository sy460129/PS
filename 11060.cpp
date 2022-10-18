#include <iostream>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int dp[1001];
int arr[1001];
int main(){
    fill(dp, dp+1001, 2147483647);
    int n; cin >> n;
    rep(i, 0, n) cin >> arr[i];
    dp[0]=0;
    rep(i, 0, n){
        rep(j, 0, arr[i]){
            dp[j]=min(dp[j], dp[i-j]+1);
        }
    }
}