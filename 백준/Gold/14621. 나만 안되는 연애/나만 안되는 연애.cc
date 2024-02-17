#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using t=tuple<int,int,int>;
char s[1001];
int dp[1001];
priority_queue<t, vector<t>, greater<t>>q, q2;
int find(int x){
	if(x==dp[x]) return x;
	else return dp[x]=find(dp[x]);
}
bool merge(int x, int y){
	x=find(dp[x]), y=find(dp[y]);
	if(x==y) return true;
	else x<y ? dp[y]=x : dp[x]=y;
	return false;
}
int main(){
	int n, m, u, v, d, ans=0; cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> s[i];
		dp[i]=i;
	}
	for(int i=0; i<m; i++){
		cin >> u >> v >> d;
		if(s[u]==s[v]) continue;
		q.push({d,u,v});
	}
	while(!q.empty()){
		auto cur=q.top(); q.pop();
		d=get<0>(cur), u=get<1>(cur), v=get<2>(cur);
		if(!merge(u,v)) ans+=d;
	}
	for(int i=1; i<n; i++){
		if(find(dp[i])!=find(dp[i+1])){
			cout << -1;
			return 0;
		}
	}
	cout << ans;
}