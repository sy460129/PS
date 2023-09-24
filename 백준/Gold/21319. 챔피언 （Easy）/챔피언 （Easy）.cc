#include <iostream>
#include <stack>
using namespace std;
int dp[200001];
int arr[200001];
stack<int>st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        cin >> dp[i];
    }
    if(n==1){
        cout << 1;
        return 0;
    }
    arr[n]=dp[n];
    for(int i=n-1; i>=1; i--){
       arr[i]=max(arr[i+1]-1, dp[i+1]);
    }
    for(int i=n; i>=1; i--){
        int t;
        if(dp[i]>dp[i-1]) {
            t=dp[i]+i-1;
            if(t>arr[i]) st.push(i);
        }
    }
    if(st.empty()){
        cout << -1;
        return 0;
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}