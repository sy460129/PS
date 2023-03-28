#include <iostream>
#include <queue>
using namespace std;
int dx[]={1,1,-1,0,1,0,-1,-1};
int dy[]={1,-1,1,1,0,-1,0,-1};
int arr[1001][1001];
queue<pair<int,int>>q, que, qu;
int n, m, cnt = 0;
void bfs(){
	while(1){
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int i=0; i<8; i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx<0 || ny<0 || nx>n-1 || ny>m-1){
					continue;
				}
				else if(arr[nx][ny]!=0){
					arr[nx][ny]--;
					if(arr[nx][ny]<=0){
						arr[nx][ny]=0;
						que.push({nx,ny});
					}
				}
			}
		}
		if(que.empty()){
			cout << cnt << "\n";
			exit(0);
		}
		cnt++;
		q=que;
		que = qu;
	}
}
int main() {
	string s;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<m; j++){
			if(s[j]=='.'){
				arr[i][j]=0;
				q.push({i,j});
			}
			else{
				arr[i][j]=s[j]-'0';
			}
		}
	}
	bfs();
}