#include <iostream>
#include <queue>
using namespace std;
int arr[100001][2];
int dp[100001][2];
int n, k;
queue<pair<int,int>>q;
void bfs(){
	while(!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		if(x==n-1 || x+k>n-1){
			cout << 1;
			exit(0);
		}
		else{
			if(arr[x+1][y]==1 && dp[x+1][y]==0){
				dp[x+1][y]=dp[x][y]+1;
				q.push({x+1,y});
			}
			if(arr[x-1][y]==1 && dp[x-1][y]==0 && x>dp[x][y]+1){
				dp[x-1][y]=dp[x][y]+1;
				q.push({x-1,y});
			}
			if(y==1){
				if(arr[x+k][0]==1 && dp[x+k][0]==0){
					dp[x+k][0]=dp[x][1]+1;
					q.push({x+k,0});
				}
			}
			else if(y==0){
				if(arr[x+k][1]==1 && dp[x+k][1]==0){
					dp[x+k][1]=dp[x][0]+1;
					q.push({x+k,1});
				}
			}
		}
	}
}
int main(){
	cin >> n >> k;
	string s, c;
	cin >> s >> c;
	for(int i=0; i<s.length(); i++){
		arr[i][0]=s[i]-'0';
	}
	for(int i=0; i<c.length(); i++){
		arr[i][1]=c[i]-'0';
	}
	q.push({0,0});
	bfs();
	cout << 0;
}