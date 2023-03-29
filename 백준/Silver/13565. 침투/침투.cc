#include <iostream>
#include <queue>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
int arr[1001][1001];
bool visit[1001][1001];
queue<pair<int,int>>q;
void bfs(){
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 || ny<0 || nx>n-1 || ny>m-1){
				continue;
			}
			else if(nx==n-1 && arr[nx][ny]==0){
				cout << "YES\n";
				exit(0);
			}
			if(arr[nx][ny]==0 && !visit[nx][ny]){
				visit[nx][ny]=true;
				q.push({nx,ny});
			}
		}
	}
}
int main(){
	string s;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<m; j++){
			arr[i][j]=s[j]-'0';
			if(i==0 && arr[i][j]==0){
				q.push({i,j});
				visit[i][j]=true;
			}
		}
	}
	bfs();
	cout << "NO\n";
}