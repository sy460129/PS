#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int arr[21][21];
int num[7];
int n, ans, t, p, now;
bool c;
bool visit[21][21];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
vector<pair<int,int>>v;
queue<pair<pair<int,int>,pair<int,int>>>q;
void bfs(){
	while(!q.empty()){
		int x=q.front().first.first; // x좌표
		int y=q.front().first.second; // y좌표
		int w=q.front().second.first; // 상어 크기
		int z=q.front().second.second+1; // 이동 횟수
		while(num[p]==0){
			p++;
			if(p>=w) c=true;
		}
		if(c) break;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 || ny<0 || nx>n-1 || ny>n-1 || visit[nx][ny] || arr[nx][ny]>w || (now!=0 && now!=z)) continue;
			if(arr[nx][ny]<w && arr[nx][ny]!=0 && !visit[nx][ny]){
				v.push_back({nx,ny});
				now=z;
				visit[nx][ny]=true;
			}
			else{
				if(v.empty()){
					q.push({{nx,ny},{w,z}});
					visit[nx][ny]=true;
				}
			}
		}
		if(q.empty() && !v.empty()){
			sort(v.begin(), v.end());
			int a=v[0].first, b=v[0].second;
			ans=now, t++;
			while(!q.empty()) q.pop();
			num[arr[a][b]]--;
			arr[a][b]=0;
			if(t==w) w++, t=0;
			q.push({{a, b},{w,now}});
			fill(visit[0], visit[n], false);
			v.clear();
			now=0;
		}
	}
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
			if(arr[i][j]==9) {
				q.push({{i,j},{2,0}});
				arr[i][j]=0;
				visit[i][j]=true;
			}
			else if(arr[i][j]!=0) num[arr[i][j]]++;
		}
	}
	bfs();
	cout << ans;
}