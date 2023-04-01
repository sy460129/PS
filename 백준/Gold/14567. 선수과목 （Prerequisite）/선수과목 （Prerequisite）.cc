#include <iostream>
#include <queue>
#include <vector>
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
	for(int i=1; i<=n; i++){
		if(arr[i]==0){
			q.push(i);
			dp[i]=1;
		}
	}
	while(!q.empty()){
		int nx=q.front();
		q.pop();
		for(int i=0; i<v[nx].size(); i++){
			int next=v[nx][i];
			arr[next]--;
			if(arr[next]==0){
				dp[next]=dp[nx]+1;
				q.push(next);
			}
		}
	}
	for(int i=1; i<=n; i++){
		cout << dp[i] << " ";
	}
}