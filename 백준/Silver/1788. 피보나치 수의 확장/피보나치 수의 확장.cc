#include <iostream>
using namespace std;
int dp[1000001];
int main(){
    bool c=true;
    int n; cin >> n;
    if(n==0){
        cout << "0\n0";
        return 0;
    }
    if(n<0) c=false, n*=-1;
    dp[1]=1;
    for(int i=2; i<=n; i++) dp[i]=(dp[i-1]+dp[i-2])%1000000000;
    if(c) cout << "1\n" << dp[n];
    else{
        n%2==0 ? cout << "-1\n" : cout << "1\n" ;
        cout << dp[n];
    }
}