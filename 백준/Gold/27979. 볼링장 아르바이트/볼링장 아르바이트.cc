#include <iostream>
#include <stack>
using namespace std;
stack<int>s;
int dp[200001];
int main(){
    int n, cnt=0, m=-1, ans=0; cin >> n;
    for(int i=0; i<n; i++) cin >> dp[i];
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && (dp[i]>s.top() || m>s.top())) {
            m=max(m, s.top());
            ans++;
            s.pop();
        }
        s.push(dp[i]);
    }
    if(s.top()<m) ans++;
    cout << ans;
}