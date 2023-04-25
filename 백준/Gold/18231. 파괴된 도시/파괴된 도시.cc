#include <iostream>
#include <vector>
using namespace std;
vector<int>v[2001];
vector<int>res;
bool check[2001];
bool visit[2001];
bool dfs(int t){
	for(int i=0; i<v[t].size(); i++){
		if(!check[v[t][i]]) return false;
	}
	return true;
}
int main(){
	int n, m, x, y, t; cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin >> t;
	while(t--){
		cin >> x;
		check[x]=true;
		visit[x]=true;
	}
	for(int i=1; i<=n; i++){
		if(!check[i]) continue;
		if(dfs(i)){
			visit[i]=false;
			for(int j=0; j<v[i].size(); j++){
				visit[v[i][j]]=false;
			}
			res.push_back(i);
		}
	}
	for(int i=1; i<=n; i++){
		if(visit[i]){
			cout << -1;
			return 0;
		}
	}
	cout << res.size() << "\n";
	for(auto e : res) cout << e << " ";
}