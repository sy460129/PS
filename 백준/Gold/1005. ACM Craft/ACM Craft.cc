#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll val[1001];
ll arr[1001];
ll dp[1001];
queue<ll>q;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n, m, x, y, ans;
	cin >> t;
	while(t--){
		vector<ll>v[1001];
		cin >> n >> m;
		for(int i=1; i<=n; i++){
			cin >> val[i];
		}
		for(int i=1; i<=m; i++){
			cin >> x >> y;
			v[x].push_back(y);
			arr[y]++;
		}
		cin >> ans;
		for(int i=1; i<=n; i++){
			if(arr[i]==0){
				q.push(i);
				dp[i]=val[i];
			}
		}
		while(!q.empty()){
			int nx=q.front();
			q.pop();
			for(int i=0; i<v[nx].size(); i++){
				int next=v[nx][i];
				arr[next]--;
				if(arr[next]==0){
					q.push(next);
				}
				if(dp[next]<val[next]+dp[nx]){
					dp[next]=val[next]+dp[nx];
				}
			}
		}
		cout << dp[ans] << "\n";
		fill(arr, arr+1001, 0);
		fill(dp, dp+1001, 0);
		fill(val, val+1001, 0);
		
	}
}