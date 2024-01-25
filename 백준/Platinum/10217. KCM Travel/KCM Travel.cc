#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
using ll=int;
using p=pair<pair<ll,ll>,ll>;
ll dist[102][10002]; // [공항][비용]
ll t, n, m, k, u, v, c, d;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        queue<p>q;
        vector<p>vec[101];
        fill(dist[0], dist[102], INF);
        dist[1][0]=0;
        cin >> n >> m >> k;
        while(k--){
            cin >> u >> v >> c >> d;
            vec[u].push_back({{v,d},c}); // {{도착, 소요시간}, 비용} 
        }
        q.push({{0,1},0}); // {{소요시간, 출발}, 비용}
        while(!q.empty()){
            ll nd=q.front().first.first, nx=q.front().first.second, nc=q.front().second;
            // nd = 소요시간, nx = 출발, nc = 비용
            q.pop();
            if(dist[nx][nc]==nd){
                for(int i=0; i<vec[nx].size(); i++){
                    ll next=vec[nx][i].first.first, dis=vec[nx][i].first.second, cost=vec[nx][i].second;
                    // next = 도착, dis = 소요시간, cost = 비용
                    if(nc+cost>m) continue;
                    if(dist[next][nc+cost]>nd+dis){
                        dist[next][nc+cost]=nd+dis;
                        if(next!=n) q.push({{dist[next][nc+cost],next},nc+cost});
                    }
                }
            }
        }
        ll res=INF;
        for(int i=0; i<10001; i++){
            res=min(res, dist[n][i]);
        }
        res==INF ? cout << "Poor KCM\n" : cout << res << "\n";
    }
}