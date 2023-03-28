#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int arr[101][101][101];
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int n, m, h, ans=0;
queue<tuple<int,int,int>>q;
void bfs(){
	while(!q.empty()){
		auto& cur=q.front();
		int x=get<0>(cur);
		int y=get<1>(cur);
		int z=get<2>(cur);
		q.pop();
		for(int i=0; i<6; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nz=z+dz[i];
			if(nx<0 || nx>m-1 || ny<0 || ny>n-1 || nz<0 || nz>h-1){
				continue;
			}
			if(arr[nx][ny][nz]==0){
				arr[nx][ny][nz]=arr[x][y][z]+1;
				q.push({nx,ny,nz});
			}
		}
	}
}
int main(){
	cin >> n >> m >> h;
	for(int i=0; i<h; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<n; k++){
				cin >> arr[j][k][i];
				if(arr[j][k][i]==1){
					q.push({j,k,i});
				}
			}
		}
	}
	bfs();
	for(int i=0; i<h; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<n; k++){
				if(arr[j][k][i]==0){
					cout << -1;
					return 0;
				}
				else{
					ans=max(ans, arr[j][k][i]);
				}
			}
		}
	}
	cout << ans-1;
}