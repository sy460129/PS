#include <iostream>
using namespace std;
int dp[21];
int arr[21];
int v[21];
int main(){
    int n, x, y;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x >> y;
        arr[i]=x;
        v[i]=y;
    }
    for(int i=1; i<=n+1; i++){
        for(int j=1; j<=n+1; j++){
            if(i==arr[j]+j) dp[i]=max(dp[i], dp[i-arr[j]]+v[j]);
            else dp[i]=max(dp[i], dp[i-1]);
        }
    }
    cout << dp[n+1];
}