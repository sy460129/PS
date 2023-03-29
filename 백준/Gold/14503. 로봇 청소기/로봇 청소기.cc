#include <iostream>
using namespace std;
int arr[51][51];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool c[51][51], flag;
int n, m, x, y, d, cnt;
int main(){
	cin >> n >> m >> x >> y >> d;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	while(1){
		bool check=false;
		if(!c[x][y]){
			cnt++, c[x][y]=true;
		}
		for(int i=0; i<4; i++){
			d--;
			if(d<0) d=3;
			int nx=x+dx[d], ny=y+dy[d];
			if(!c[nx][ny] && !arr[nx][ny]){
				x=nx, y=ny;
				check=true;
				break;
			}
		}
		if(!check){
			x-=dx[d], y-=dy[d];
			if(arr[x][y]) flag=true;
		}
		if(flag) break;
	}
	cout << cnt;
}