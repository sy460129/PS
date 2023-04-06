#include <iostream>
#include <queue>
using namespace std;
int n, m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char arr[101][101];
bool a[101][101];
queue<pair<int,int>>w;
void bfs(){
	while(!w.empty()){
		int x=w.front().first, y=w.front().second;
		w.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 || ny<0 || nx>n-1 || ny>m-1 || a[nx][ny]){
				continue;
			}
			if(arr[nx][ny]=='.'){
				a[nx][ny]=true;
				w.push({nx,ny});
			}
			else{
				if(arr[nx][ny]=='+'){
					while(arr[nx][ny]=='+'){
						nx+=dx[i],ny+=dy[i];
					}
					if(arr[nx][ny]=='#'){
						nx-=dx[i],ny-=dy[i];
					}
					if(!a[nx][ny]){
						a[nx][ny]=true;
						w.push({nx,ny});
					}
				}
			}
		}
	}
}
int main(){
	cin >> n >> m;
	string s;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<m; j++){
			arr[i][j]=s[j];
			if(s[j]=='W'){
				w.push({i,j});
			}
		}
	}
	bfs();
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j]=='.' && !a[i][j]){
				arr[i][j]='P';
			}
			cout << arr[i][j];
		}
		cout << "\n";
	}
}