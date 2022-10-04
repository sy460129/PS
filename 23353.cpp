#include <iostream>
#include <queue>
using namespace std;
int arr[1002][1002];
int dp[1002][1002][8];
queue<pair<int,int>>q;
priority_queue<int>pq, pq2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, ans=-1;
	cin >> n;
	if(n==2){
		cout << "2";
		return 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> arr[i][j];
			if(arr[i][j]==2) q.push({i,j});
			else if(arr[i][j]==1){
				for(int k=0; k<8; k++) dp[i][j][k]=1;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(arr[i][j]==1){
				if(arr[i][j-1]==1) dp[i][j][0]=dp[i][j-1][0]+1;
				if(arr[i-1][j]==1) dp[i][j][2]=dp[i-1][j][2]+1;
				if(arr[i-1][j+1]==1) dp[i][j][4]=dp[i-1][j+1][4]+1;
				if(arr[i-1][j-1]==1) dp[i][j][6]=dp[i-1][j-1][6]+1;
			}
		}
	}
	for(int i=n; i>=1; i--){
		for(int j=n; j>=1; j--){
			if(arr[i][j]==1){
				if(arr[i][j+1]==1) dp[i][j][1]=dp[i][j+1][1]+1;
				if(arr[i+1][j]==1) dp[i][j][3]=dp[i+1][j][3]+1;
				if(arr[i+1][j-1]==1) dp[i][j][5]=dp[i+1][j-1][5]+1;
				if(arr[i+1][j+1]==1) dp[i][j][7]=dp[i+1][j+1][7]+1;
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=0; k<8; k++){
				ans=max(ans, dp[i][j][k]);
			}
		}
	}
	while(!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		pq.push(dp[x][y-1][0]+dp[x][y+1][1]);
		pq.push(dp[x-1][y][2]+dp[x+1][y][3]);
		pq.push(dp[x-1][y+1][4]+dp[x+1][y-1][5]);
		pq.push(dp[x-1][y-1][6]+dp[x+1][y+1][7]);
		ans=max(ans, pq.top()+1);
		pq=pq2;
	}
	cout << ans;
}