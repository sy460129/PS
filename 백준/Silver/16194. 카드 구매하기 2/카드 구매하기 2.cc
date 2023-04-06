#include <iostream>
#define rep(i, a, b) for(int i=a; i<=b; i++)
using namespace std;
int dp[1002];
int arr[1002];
int main(){
    int n; cin >> n;
    rep(i, 1, n) cin >> arr[i];
    rep(i, 1, n){
        dp[i]=arr[i];
        rep(j, 1, i){
            dp[i]=min(dp[i], dp[i-j]+arr[j]);
        }
    }
    cout << dp[n];
}