#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
using ll=long long;
using t=tuple<ll, ll, ll>;
priority_queue<t, vector<t>, greater<t>>q;
int arr[10001];
int find(int x){
    if(x==arr[x]){
        return x;
    }
    else{
        return x=find(arr[x]);
    }
}
bool merge(int a, int b){
    a=find(a);
    b=find(b);
    if(a==b) return true;
    a>b ? arr[a]=b : arr[b]=a;
    return false;
}
int main(){
    ll n, m, a, b, c, cnt=0; cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        q.push({c,a,b});
    }
    for(int i=1; i<=n; i++){
        arr[i]=i;
    }
    while(!q.empty()){
        auto cur=q.top(); q.pop();
        ll x=get<0>(cur);
        ll y=get<1>(cur);
        ll z=get<2>(cur);
        if(!merge(y, z)) cnt+=x;
    }
    cout << cnt;
}