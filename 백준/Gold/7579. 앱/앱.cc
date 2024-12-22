#include <iostream>
using namespace std;
int dp[101][10001];
int N[101], c[101];
int main(){
  int n, m, ans=0; cin >> n >> m;
  for(int i=1; i<=n; i++) cin >> N[i];
  for(int i=1; i<=n; i++){
    cin >> c[i];
    ans+=c[i];
  }
  for(int i=1; i<=n; i++){
    for(int j=0; j<=ans; j++){
        if(j<c[i]) dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        else dp[i][j]=max(dp[i-1][j-c[i]]+N[i], dp[i-1][j]);
    }
  }
  for(int i=0; i<=ans; i++){
    if(dp[n][i]>=m){
        cout << i;
        return 0;
    }
  }
}