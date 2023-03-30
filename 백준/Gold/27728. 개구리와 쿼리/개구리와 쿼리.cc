#include <iostream>
#include <queue>
using namespace std;
int arr[502][502];
int dp[502][502];
int mi[502][502];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, x, y, l; cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> arr[i][j];
			if(i==1) mi[i-1][j]=2147483647;
			dp[i][j]=dp[i][j-1]+arr[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			mi[i][j]=min(mi[i-1][j],dp[i][n]-dp[i][j-1]);
		}
	}
	while(m--){
		cin >> x >> y >> l;
		int ans=dp[x][n]-dp[x][y-1];
		for(int i=y; i<=n; i++){
			ans=min(ans, mi[x-l][i]+dp[x][i-1]-dp[x][y-1]);
		}
		cout << ans << "\n";
	}
}