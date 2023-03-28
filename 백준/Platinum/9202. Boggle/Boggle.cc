#include <iostream>
using namespace std;
string arr[300001];
char b[4][4];
bool check[4][4], c;
int a[]={0,0,0,1,1,2,3,5,11};
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={0,1,-1,0,1,-1,1,-1};
int ans, cnt;
string res;
void dfs(int t, int p, int x, int y){
	if(t==arr[p].length()){
		c=true;
		ans+=a[t];
		cnt++;
		if(t>=res.length()){
			if(t>res.length()) res=arr[p];
			else res=min(res,arr[p]);
		}
		return;
	}
	for(int j=0; j<8; j++){
		int nx=x+dx[j], ny=y+dy[j];
		if(c|| nx<0 || ny<0 || nx>3 || ny>3 || check[nx][ny] || arr[p][t]!=b[nx][ny]) continue;
		check[nx][ny]=true;
		dfs(t+1,p,nx,ny);
		check[nx][ny]=false;
		if(c) return;
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, t; cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	cin >> t;
	while(t--){
		ans=0, cnt=0;
		res="";
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				cin >> b[i][j];
			}
		}
		for(int i=0; i<n; i++){
			c=false;
			for(int j=0; j<4; j++){
				for(int k=0; k<4; k++){
					if(arr[i][0]==b[j][k]){
						check[j][k]=true;
						dfs(1,i,j,k);
						check[j][k]=false;
					}
					if(c) break;
				}
				if(c) break;
			}
		}
		cout << ans << " " << res << " " << cnt << "\n";
	}
}