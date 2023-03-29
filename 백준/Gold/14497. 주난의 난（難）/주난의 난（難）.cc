#include <iostream>
#include <queue>
using namespace std;
int arr[301][301];
bool visit[301][301];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
queue<pair<int,int>>q, q2, q3;
int n, m, a, b, c, d, cnt=0;
void bfs(){
	while(!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<1 || ny<1 || nx>n || ny>m || visit[nx][ny]){
				continue;
			}
			else if(nx==c && ny==d){
				cout << cnt;
				exit(0);
			}
			else if(arr[nx][ny]==0){
				q.push({nx,ny});
				visit[nx][ny]=true;
			}
			else if(arr[nx][ny]==1){
				q2.push({nx,ny});
				arr[nx][ny]=0;
				visit[nx][ny]=true;
			}
		}
	}
}
int main(){
	string s;
	cin >> n >> m >> a >> b >> c >> d;
	for(int i=1; i<=n; i++){
		cin >> s;
		for(int j=1; j<=m; j++){
			if(s[j-1]=='*'){
				q.push({i,j});
				visit[i][j]=true;
			}
			else if(s[j-1]=='#'){
				continue;
			}
			else{
				arr[i][j]=s[j-1]-'0';
			}
		}
	}
	
	while(1){
		cnt++;
		bfs();
		q=q2, q2=q3;
	}
}