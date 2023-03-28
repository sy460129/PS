#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dp[101];
bool check[101], c[101];
int m, ans;
queue<pair<int,int>>q;
vector<int>v[101], v2, v3, v4[101];
int find(int x){
	if(x==dp[x]) return x;
	else{
		return dp[x]=find(dp[x]);
	}
}
void merge(int a, int b){
	a=find(a), b=find(b);
	if(a!=b){
		a<b ? dp[b]=a : dp[a]=b;
	}
}
void bfs(){
	m=0;
	while(!q.empty()){
		int x=q.front().first, y=q.front().second; q.pop();
		m=max(m, y);
		for(int i=0; i<v[x].size(); i++){
			if(!check[v[x][i]]){
				check[v[x][i]]=true;
				q.push({v[x][i],y+1});
			}
		}
	}
}
void dfs(int n){
	int res=n, ans=2147483647;
	for(int i=0; i<v4[n].size(); i++){
		q.push({v4[n][i],0});
		fill(check, check+101, false);
		check[v4[n][i]]=true;
		bfs();
		if(ans>m){
			res=v4[n][i];
			ans=m;
		}
	}
	v3.push_back(res);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, x, y; cin >> n >> m;
	for(int i=1; i<=n; i++) dp[i]=i;
	for(int i=0; i<m; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		merge(x,y);
	}
	for(int i=1; i<=n; i++){
		if(find(dp[i])==i) v2.push_back(i);
		v4[dp[i]].push_back(i);
	}
	for(int i=0; i<v2.size(); i++){
		dfs(v2[i]);
	}
	cout << v3.size() << "\n";
	sort(v3.begin(), v3.end());
	for(auto e : v3) cout << e << "\n";
}