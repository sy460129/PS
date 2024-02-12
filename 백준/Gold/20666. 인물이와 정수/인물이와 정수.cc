#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll=unsigned long long;
using p=pair<ll,ll>;
ll dp[100001];
bool check[100001];
vector<p>v[100001];
priority_queue<p, vector<p>, greater<p>>q;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, p, a, b, t, cnt=0; cin >> n >> m;
	ll res=0;
	for(int i=1; i<=n; i++) cin >> dp[i];
	cin >> p;
	while(p--){
		cin >> a >> b >> t;
		dp[b]+=t;
		v[a].push_back({b,t});
	}
	for(int i=1; i<=n; i++) q.push({dp[i],i});
	while(cnt!=m){
		auto cur=q.top(); q.pop();
		t=cur.second;
		if(check[t]) continue;
		check[t]=true;
		for(auto e : v[t]){
			dp[e.first]-=e.second;
			if(!check[e.first]) q.push({dp[e.first], e.first});
		}
		res=max(res, cur.first);
		cnt++;
	}
	cout << res;
}