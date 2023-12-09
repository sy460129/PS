#include <string>
#include <vector>
#include <set>
using namespace std;
set<int>s;
int dp[1001][1001];
int solution(vector<int>v) {
    for(int i=0; i<v.size(); i++) dp[0][i]=v[i], s.insert(v[i]);
    for(int i=1; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            dp[i][j]=dp[i-1][j]+v[(i+j)%((int)v.size())];
            s.insert(dp[i][j]);
        }
    }
    int answer = s.size();
    return answer;
}