#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using pi=pair<int,int>;
int non[301][301];
int dp[301];
bool check[301];
priority_queue<pi, vector<pi>, greater<pi>>q;
int main(){
	int n, x, y, ans=0; cin >> n;
	pair<int,int>p={1e9,0};
	for(int i=1; i<=n; i++){
		cin >> dp[i];
		q.push({dp[i],i});
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> non[i][j];
		}
	}
	while(!q.empty()){
		x=q.top().first, y=q.top().second; q.pop();
		x<dp[y] ? ans+=x : ans+=dp[y];
		check[y]=true;
		for(int i=1; i<=n; i++){
			if(!check[i]) q.push({non[y][i],i});
		}
		while(!q.empty() && check[q.top().second]) q.pop();
	}
	cout << ans;
}