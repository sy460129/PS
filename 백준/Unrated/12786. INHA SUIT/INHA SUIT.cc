#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
vector<int>v[101];
queue<tuple<int,int,int>>q;
int dp[101][21];
int n, t, ans=102;
void bfs(){
	while(!q.empty()){
		auto cur=q.front(); q.pop();
		int x=get<0>(cur), y=get<1>(cur), z=get<2>(cur);
		if(x>n){
			ans=min(ans, z);
			continue;
		}
		for(int i=0; i<v[x].size(); i++){
			if(v[x][i]==y){
				if(dp[x][y]>z){
					dp[x][y]=z;
					q.push({x+1,y,z});
				}
			}
			else if(v[x][i]==y+1){
				if(dp[x][y+1]>z){
					dp[x][v[x][i]]=z;
					q.push({x+1,y+1,z});
				}
			}
			else if(v[x][i]==min(20,y*2)){
				if(y>=10) y=10;
				if(dp[x][y*2]>z){
					dp[x][y*2]=z;
					q.push({x+1,y*2,z});
				}
			}
			else if(v[x][i]==y-1){
				if(dp[x][y-1]>z){
					dp[x][y-1]=z;
					q.push({x+1,y-1,z});
				}
			}
			if(z<t && dp[x][v[x][i]]>z+1){
				dp[x][v[x][i]]=z+1;
				q.push({x+1,v[x][i],z+1});
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, a; cin >> n >> t;
	for(int i=1; i<=n; i++){
		cin >> m;
		while(m--){
			cin >> a;
			v[i].push_back(a);
		}
	}
	fill(dp[0], dp[101], 2147483647);
	q.push({1,1,0});
	bfs();
	ans<102 ? cout << ans : cout << -1;
}