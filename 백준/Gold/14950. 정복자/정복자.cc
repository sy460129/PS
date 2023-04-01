#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using ll=long long;
using t=tuple<ll,ll, ll>;
priority_queue<t, vector<t>, greater<t>>q;
ll arr[10001];
ll find(ll x){
    if(x==arr[x]) return x;
    else return x=find(arr[x]);
}
bool merge(ll x, ll y){
    x=find(arr[x]);
    y=find(arr[y]);
    if(x==y) return true;
    else{
        x>y ? arr[x]=y : arr[y]=x;
        return false;
    }
}
ll cnt;
int main(){
    int n, m, t, a, b, c, p=0;
    for(int i=1; i<=10000; i++) arr[i]=i;
    cin >> n >> m >> t;
    while(m--){
        cin >> a >> b >> c;
        q.push({c,a,b});
    }
    while(!q.empty()){
        auto cur=q.top(); q.pop();
        ll x=get<0>(cur);
        ll y=get<1>(cur);
        ll z=get<2>(cur);
        if(!merge(y, z)){
            cnt+=x;
            p++;
            cnt+=t*(p-1);
        }
    } 
    cout << cnt;
}