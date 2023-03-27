#include <iostream>
#include <iomanip>
using namespace std;
int n, cnt;
double arr[4], p=1, ans=0;
bool visit[51][51];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void dfs(int t, int x, int y){
	if(t==n){
		ans+=p;
		return;
	}
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(!arr[i] || visit[nx][ny]) continue;
		visit[nx][ny]=true;
		p*=arr[i];
		dfs(t+1,nx,ny);
		p/=arr[i];
		visit[nx][ny]=false;
	}
}
int main(){
	cin >> n;
	for(int i=0; i<4; i++){
		cin >> arr[i];
		arr[i]/=100;
	}
	visit[25][25]=true;
	dfs(0,25,25);
	cout << fixed << setprecision(9) << ans;
}