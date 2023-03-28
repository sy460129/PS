#include <iostream>
using namespace std;
int dp[201][201];
int main(){
    string s, c;
    while(1){
        cin >> s >> c;
        if(cin.eof()){
            return 0;
        }
        fill(dp[0], dp[201], 0);
        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=c.length(); j++){
                if(s[i-1]==c[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << dp[s.length()][c.length()] << "\n";
    }
}