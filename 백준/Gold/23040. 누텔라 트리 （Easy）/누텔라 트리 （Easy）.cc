#include <iostream>
#include <vector>
#include <queue>
#define rep(i, a, b) for(int i=a; i<=b; i++)
using namespace std;
vector<int>v[100001];
int dp[100001];
int arr[100001];
bool visit[100001];
queue<int>q;
string color;
int find(int x){
	if(x==arr[x]) return x;
	else return arr[x]=find(arr[x]);
}
void merge(int x, int y){
	x=find(arr[x]);
	y=find(arr[y]);
	x<y ? arr[y]=x : arr[x]=y;
}
int bfs(){
	int cnt=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		rep(i, 0, v[x].size()-1){
			if(color[v[x][i]-1]=='R'){
				if(!visit[v[x][i]]){
					visit[v[x][i]]=true;
					merge(arr[x], arr[v[x][i]]);
					q.push(v[x][i]);
				}
			}
			else cnt++;
		}
	}
	return cnt;
}
int main(){
	int n, x, y; cin >> n;
	long long ans=0;
	rep(i, 1, n) arr[i]=i;
	rep(i, 1, n-1){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin >> color;
	rep(i, 1, n){
		if(color[i-1]=='R' && !visit[i]){
			visit[i]=true;
			q.push(i);
			dp[i]=bfs();
		}
	}
	rep(i, 1, n){
		dp[i]=dp[arr[i]];
		if(color[i-1]=='R') ans+=dp[i];
	}
	cout << ans;
}