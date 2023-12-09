#include <string>
#include <vector>
#include <cmath>
using namespace std;
pair<int,int>dp[5000002];
int arr[5000001];
vector<int> solution(int e, vector<int> s) {
    vector<int> answer;
    for(int i=2; i<=e; i++){
        for(int j=1; j<=e/i; j++){
            arr[i*j]++;
        }
    }
    for(int i=e; i>=1; i--){
        dp[i]={arr[i],i};
        if(dp[i].first<dp[i+1].first) dp[i]=dp[i+1];
    }
    for(int i=0; i<s.size(); i++){
        answer.push_back(dp[s[i]].second);
    }
    return answer;
}