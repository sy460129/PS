#include <iostream>
#include <queue>
#include <vector>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int dp[1001];
int arr[1001];
queue<int>q;
vector<int>v[1001];
int main(){
	int n, m, x, y;
	cin >> n >> m;
	while(m--){
		cin >> x >> y;
		arr[y]++;
		v[x].push_back(y);
	}
	rep(i, 1, n+1){
		if(arr[i]==0) q.push(i), dp[i]=1;
	}
	while(!q.empty()){
		int nx=q.front();
		q.pop();
		rep(i, 0, v[nx].size()){
			int next=v[nx][i];
			arr[next]--;
			if(arr[next]==0) dp[next]=dp[nx]+1, q.push(next);
		}
	}
	rep(i, 1, n+1){
		cout << dp[i] << " ";
	}
}