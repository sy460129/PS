#include <iostream>
#include <vector>
using namespace std;
vector<int>v[51];
int dp[51];
bool c[51], check;
int find(int x){
	if(dp[x]==x) return x;
	else return dp[x]=find(dp[x]);
}
void merge(int x, int y){
	x=find(dp[x]);
	y=find(dp[y]);
	x<y ? dp[y]=x : dp[x]=y;
	if(c[x] || c[y]) c[dp[x]]=true, c[dp[y]]=true;
}
int main() {
	int n, m, t, k, x, cnt=0; cin >> n >> m >> k;
	for(int i=1; i<=n; i++) dp[i]=i;
	for(int i=0; i<k; i++){
		cin >> x;
		c[x]=true;
	}
	for(int i=0; i<m; i++){
		cin >> x;
		while(x--){
			cin >> t;
			v[i].push_back(t);
		}
		for(int j=1; j<v[i].size(); j++){
			merge(v[i][0], v[i][j]);
		}
	}
	for(int i=0; i<m; i++){
		check=false;
		for(int j=0; j<v[i].size(); j++){
			if(c[find(dp[v[i][j]])]) check=true;
		}
		if(!check) cnt++;
	}
	cout << cnt;
}