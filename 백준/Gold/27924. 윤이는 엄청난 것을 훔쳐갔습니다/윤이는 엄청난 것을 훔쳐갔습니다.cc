#include <iostream>
#include <vector>
using namespace std;
vector<int>v[200001], vec;
int dp[3][200001];
void dfs(int k, int t){
	for(int i=0; i<v[t].size(); i++){
		if(!dp[k][v[t][i]]){
			dp[k][v[t][i]]=dp[k][t]+1;
			dfs(k,v[t][i]);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, x, y, a, b, c; cin >> n;
	for(int i=0; i<n-1; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1; i<=n; i++){
		if(v[i].size()==1) vec.push_back(i);
	}
	cin >> a >> b >> c;
	dp[0][a]=1, dp[1][b]=1, dp[2][c]=1;
	dfs(0,a);
	dfs(1,b);
	dfs(2,c);
	for(int i=0; i<vec.size(); i++){
		if(dp[0][vec[i]]<dp[1][vec[i]] && dp[0][vec[i]]<dp[2][vec[i]]){
			cout << "YES";
			return 0;
		}
	}	
	cout << "NO";
}