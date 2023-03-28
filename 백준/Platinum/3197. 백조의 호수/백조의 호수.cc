#include <iostream>
#include <queue>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool visit[1501][1501];
queue<pair<int,int>>q, q2, que, qorwh, qorwh2;
int n, m, res=0;
char arr[1501][1501];
void bfs(){
	while(1){
		while(!qorwh.empty()){
			int a=qorwh.front().first,b=qorwh.front().second;
			qorwh.pop();
			for(int i=0; i<4; i++){
				int rx=a+dx[i];
				int ry=b+dy[i];
				if(rx<0||ry<0||rx>n-1||ry>m-1){
					continue;
				}
				if(arr[rx][ry]=='.'){
					visit[rx][ry]=true;
					qorwh.push({rx,ry});
					arr[rx][ry]='A';
				}
				else if(arr[rx][ry]=='X' && !visit[rx][ry]){
					qorwh2.push({rx,ry});
					visit[rx][ry]=true;
				}
				if(arr[rx][ry]=='T'){
					cout << res;
					exit(0);
				}
			}
		}
		qorwh=qorwh2;
		qorwh2=que;
		while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			q.pop();
			for(int i=0; i<4; i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx<0||ny<0||nx>n-1||ny>m-1){
					continue;
				}
				if(arr[nx][ny]=='X'){
					q2.push({nx,ny});
					arr[nx][ny]='.';
				}
			}
		}
		q=q2;
		q2=que;
		res++;
	}
}
int main(){
	string s;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<m; j++){
			arr[i][j]=s[j];
			if(s[j]=='.'){
				q.push({i,j});
			}
			else if(s[j]=='L'){
				visit[i][j]=true;
				if(qorwh.empty()){
					arr[i][j]='A';
					q.push({i,j});
					qorwh.push({i,j});
				}
				else{
					arr[i][j]='T';
					q.push({i,j});
				}
			}
		}
	}
	bfs();
}