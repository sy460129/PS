#include <iostream>
using namespace std;
int dp[100001], arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k, q, x=1; cin >> n >> k >> q;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=1; i<=n; i++){
        if(arr[i]!=k){
            dp[i]+=(dp[i-1]+x);
            x++;
        }
        else dp[i]=dp[i-1], x=1;
    }
    while(q--){
        cin >> x;
        cout << dp[x] << "\n";
    }
}