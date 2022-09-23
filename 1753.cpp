#include <iostream>
#include <vector>
#include <queue>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define INF 2147483647
using namespace std;
using p=pair<int,int>;
vector<p>v[20001];
int dp[20001];
priority_queue<p, vector<p>, greater<p>>q;
int main(){
    int t, e, a, b, c, s;
    cin >> t >> e >> s;
    while(e--){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    rep(i, 1, t+1){
        dp[i]=INF;
    }
    dp[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int x=q.top().first, y=q.top().second; q.pop();
        rep(i, 0, v[y].size()){
            int nx=v[y][i].first;
            int cost=v[y][i].second;
            if(dp[nx]>x+cost){
                dp[nx]=x+cost;
                q.push({dp[nx],nx});
            }
        }
    }
    rep(i, 1, t+1) dp[i]==INF ? cout << "INF\n" : cout << dp[i] << "\n";
}