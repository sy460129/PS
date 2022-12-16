#include <iostream>
#include <queue>
using namespace std;
int dx[]={1,-1,0,0,1,-1,1,-1,0};
int dy[]={-1,1,1,-1,0,0,1,-1,0};
char arr[8][8];
bool visit[8][8];
queue<pair<int,int>>q, q2;
void bfs(){
	while(!q.empty()){
		fill(visit[0], visit[8], 0);
		while(!q.empty()){
			int x=q.front().first, y=q.front().second; q.pop();
			if(x==0 && y==7){
				cout << 1;
				exit(0);
			}
			if(arr[x][y]=='.'){
				for(int i=0; i<9; i++){
					int nx=x+dx[i];
					int ny=y+dy[i];
					if(nx<0 || ny<0 || nx>7 || ny>7 || arr[nx][ny]=='#' || visit[nx][ny]) continue;
					visit[nx][ny]=true;
					q2.push({nx,ny});
				}
			}
		}
		for(int i=7; i>=0; i--){
			for(int j=0; j<8; j++){
				if(i==0) arr[i][j]='.';
				else arr[i][j]=arr[i-1][j];
			}
		}
		q=q2;
		while(!q2.empty()) q2.pop();
	}
}
int main(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cin >> arr[i][j];
		}
	}
	q.push({7,0});
	bfs();
	cout << 0;
}