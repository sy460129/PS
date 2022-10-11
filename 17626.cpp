#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int dp[50001];
int main(){
    vector<int>v;
    int n; cin >> n;
    for(int i=1; i<=sqrt(n); i++){
        v.push_back(i*i);
    }
    for(int i=1; i<=n; i++){
        dp[i]=dp[i-1]+1;
        for(int j=0; j<v.size(); j++){
            if(v[j]<=i){
                dp[i]=min(dp[i], dp[i-v[j]]+1);
            }
            else break;
        }
    }
    cout << dp[n];
}