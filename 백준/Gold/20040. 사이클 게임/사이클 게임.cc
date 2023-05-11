#include <iostream>
using namespace std;
int dp[500001];
int find(int x){
	if(x==dp[x]) return x;
	else return dp[x]=find(dp[x]);
}
bool merge(int x, int y){
	x=find(dp[x]);
	y=find(dp[y]);
	if(x!=y){
		x>y ? dp[x]=y : dp[y]=x;
		return false;
	}
	return true;
}
int main(){
	int n, m, x, y, ans=0; cin >> n >> m;
	for(int i=0; i<n; i++) dp[i]=i;
	for(int i=1; i<=m; i++){
		cin >> x >> y;
		if(ans) continue;
		if(merge(x,y)) ans=i;
	}
	cout << ans;
}