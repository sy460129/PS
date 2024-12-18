#include <iostream>
using namespace std;
int dp[1001][1001];
int main(){
  string s, c; cin >> s >> c;
  for(int i=1; i<=1000; i++) dp[i][0]=i;
  for(int j=1; j<=1000; j++) dp[0][j]=j;
  for(int i=1; i<=s.length(); i++){
    for(int j=1; j<=c.length(); j++){
      if(s[i-1]==c[j-1]) dp[i][j]=dp[i-1][j-1];
      else dp[i][j]=min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
    }
  }
  cout << dp[s.length()][c.length()];
}