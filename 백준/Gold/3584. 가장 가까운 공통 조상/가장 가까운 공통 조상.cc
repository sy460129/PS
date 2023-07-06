#include <iostream>
#include <vector>
using namespace std;
int dp[10001], p[10001];
vector<int>v[10001];
bool visit[10001];
void depth(int n, int x){
	for(int i=0; i<v[n].size(); i++){
		dp[v[n][i]]=x+1;
		depth(v[n][i], x+1);
	}
}
void find(int a, int b){
	while(dp[a]!=dp[b]) b=p[b];
	while(a!=b) a=p[a], b=p[b];
	cout << a << "\n";
}
int main(){
	int t, a, b, n; cin >> t;
	while(t--){
		cin >> n;
		for(int i=1; i<n; i++){
			cin >> a >> b;
			v[a].push_back(b);
			p[b]=a;
			visit[b]=true;
		}
		for(int i=1; i<=n; i++){
			if(!visit[i] && p[i]==0) depth(i, 0);
		}
		cin >> a >> b;
		if(dp[a]>dp[b]) swap(a, b);
		find(a, b);
		for(int i=1; i<=n; i++) v[i].clear();
		fill(visit, visit+n+1, false);
		fill(dp, dp+n+1, 0);
		fill(p, p+n+1, 0);
	}
}