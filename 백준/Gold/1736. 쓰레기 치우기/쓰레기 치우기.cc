#include <iostream>
#include <queue>
using namespace std;
using p=pair<int,int>;
bool dp[101][101];
priority_queue<p, vector<p>, greater<p>>q, q2;
int main(){
	int n, m, x, y, a=0, b=0, cnt=0; cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> dp[i][j];
			if(dp[i][j]) q.push({i,j});
		}
	}
	while(!q.empty()){
		while(!q.empty()){
			x=q.top().first, y=q.top().second; q.pop();
			if(x>=a && y>=b) a=x, b=y;
			else q2.push({x,y});
		}
		cnt++;
		a=b=0;
		while(!q2.empty()) q.push(q2.top()), q2.pop();
	}
	cout << cnt;
}