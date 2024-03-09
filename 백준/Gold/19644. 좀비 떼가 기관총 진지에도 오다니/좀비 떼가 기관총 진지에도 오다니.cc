#include <iostream>
using namespace std;
int dp[3000003];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int l, m, k, c, z, x; cin >> l >> m >> k >> c;
    bool check=true;
    x=k;
    for(int i=1; i<=l; i++){
        cin >> z;
        x=dp[i-1]-dp[max(0, i-m)];
        if(x+k>=z) dp[i]=dp[i-1]+k;
        else{
            if(c){
                c--, dp[i]=dp[i-1];
            }
            else check=false;
        }
    }
    !check ? cout << "NO" : cout << "YES";
}