#include <iostream>
#include <stack>
using namespace std;
using ll=long long;
ll dp[200001];
ll arr[200001];
ll brr[200001];
stack<ll>st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
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
    brr[1]=dp[1];
    for(int i=2; i<=n; i++){
       brr[i]=max(brr[i-1]-1, dp[i-1]);
    }
    for(int i=n; i>=1; i--){
        ll t;
        if(dp[i]>brr[i]) {
            t=dp[i]+i-1;
            if(t>arr[i]) st.push(i);
        }
        else if(dp[i]>arr[i]){
            t=dp[i]+n-i+1;
            if(t>brr[i]) st.push(i);
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