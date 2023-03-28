#include <iostream>
#include <iomanip>
using namespace std;
double dp[10001];
int main(){
    int n; cin >> n;;
    double ans=0;
    for(int i=0; i<n; i++){
        cin >> dp[i];
        if(i==0) ans=dp[i];
        else if(dp[i]*dp[i-1]>1 && dp[i-1]>1) dp[i]*=dp[i-1];
        ans=max(ans, dp[i]);
    }
    cout << fixed << setprecision(3) << ans;
}