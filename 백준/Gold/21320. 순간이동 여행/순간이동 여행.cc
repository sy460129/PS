#include <iostream>
#include <cstring>
using namespace std;
int dp[3001];
int main(){
    int n, t;
    cin >> n >> t;
    for(int i=2; i<=n; i++){
        i%2==0 ? dp[i]=(dp[i-1]*2+1)%1000000007 : dp[i]=(dp[i-1]*2)%1000000007;
    }
    if(n%2==0){
        t%2!=0 ? cout << dp[n] : cout << dp[n]-1;
    }
    else{
        t%2!=0 ? cout << dp[n] : cout << dp[n]+1;
    }
}