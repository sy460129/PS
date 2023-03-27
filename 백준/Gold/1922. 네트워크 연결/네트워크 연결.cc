#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using t=tuple<int,int,int>;
priority_queue<t, vector<t>, greater<t>>q;
int arr[1001];
int find(int x){
    if(x==arr[x]) return x;
    else{
        return x=find(arr[x]);
    }
}
bool merge(int a, int b){
    a=find(arr[a]);
    b=find(arr[b]);
    if(a==b) return true;
    else{
        a>b ? arr[a]=b : arr[b]=a;
        return false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, c, ans=0; cin >> n >> m;
    for(int i=1; i<=n; i++) arr[i]=i;
    while(m--){
        cin >> a >> b >> c;
        q.push({c,a,b});
    }
    while(!q.empty()){
        auto cur=q.top(); q.pop();
        int x=get<0>(cur);
        int y=get<1>(cur);
        int z=get<2>(cur);
        if(!merge(y, z)){
            ans+=x;
        }
    }
    cout << ans;
}