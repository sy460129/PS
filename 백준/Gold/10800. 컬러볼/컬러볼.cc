#include <iostream>
#include <set>
#include <tuple>
#include <map>
using namespace std;
using ll=long long;
set<tuple<int,int,int>>s;
map<ll, ll>m[2001];
ll color[200001];
ll dp[200001];
ll arr[2001];
ll res;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x, y, z; cin >> n;
    for(int i=0; i<n; i++){
        cin >> y >> x;
        s.insert({x,y,i});
        color[y]+=x;
        m[x][y]++;
        res+=x;
        arr[x]++;
    }
    while(!s.empty()){
        auto it=--s.end();
        x=get<0>(*(it));
        y=get<1>(*(it));
        z=get<2>(*(it));
        s.erase(it);
        dp[z]=res-color[y]-(arr[x]-1)*x+max((ll)0, m[x][y]-1)*x;
        res-=x;
        arr[x]--;
        color[y]-=x;
        m[x][y]--;
        m[x][y]=max((ll)0, m[x][y]);
    }
    for(int i=0; i<n; i++){
        cout << dp[i] << "\n";
    }
}