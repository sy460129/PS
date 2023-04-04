#include <iostream>
using namespace std;
char arr[2001][2001];
int n;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void bfs(int x, int y){
	int nx=x, ny=y;
	for(int i=0; i<4; i++){
		while(1){
			if(arr[nx][ny]=='B') arr[nx][ny]='.'; 
			if(nx+dx[i]<0 || nx+dx[i]>n-1 || ny+dy[i]<0 || ny+dy[i]>n-1 || arr[nx+dx[i]][ny+dy[i]]=='O' || arr[nx+dx[i]][ny+dy[i]]=='X'){
				break;
			}
			nx+=dx[i], ny+=dy[i];
		}
		nx=x, ny=y;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	string s;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<n; j++){
			arr[i][j]=s[j];
			if(s[j]=='.') arr[i][j]='B';
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j]=='O') bfs(i, j);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
}