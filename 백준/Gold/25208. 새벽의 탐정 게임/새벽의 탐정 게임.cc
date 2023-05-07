#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
queue<tuple<int,int,int>>q;
int n, m;
char arr[501][501];
int visit[501][501][6];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int dh[4][6]={{2,0,5,3,4,1}, {1,5,0,3,4,2}, {4,1,2,0,5,3}, {3,1,2,5,0,4}};
void bfs(){
	while(!q.empty()){
		auto cur=q.front();
		int x=get<0>(cur);
		int y=get<1>(cur);
		int h=get<2>(cur);
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nh=dh[i][h];
			if(arr[nx][ny]=='#') continue;
			if(arr[nx][ny]=='R'){
				if(nh!=0) continue;
                else{
                    cout << visit[x][y][h];
				    exit(0);
                }
			}
			if(!visit[nx][ny][nh]){
				q.push({nx,ny,nh});
				visit[nx][ny][nh]=visit[x][y][h]+1;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
			if(arr[i][j]=='D'){
				q.push({i,j,0});
				visit[i][j][0]=1;
			}
		}
	}
	bfs();
	cout << -1;
}