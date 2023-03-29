#include <iostream>
#include <vector>
using namespace std;
int dp[101][301][301];
vector<pair<int,int>>v;
int main(){
	int n, m, k, x, y, ma=-1; cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		if(x<=m && y<=k) v.push_back({x,y});
	}
	for(int l=1; l<=v.size(); l++){
		for(int i=1; i<=m; i++){
			for(int j=1; j<=k; j++){
				if(v[l-1].first<=i && v[l-1].second<=j){
					dp[l][i][j]=max(dp[l-1][i][j], dp[l-1][i-v[l-1].first][j-v[l-1].second]+1);
				}
				else dp[l][i][j]=dp[l-1][i][j];
			}
		}
	}
	for(int l=1; l<=n; l++){
		for(int i=1; i<=m; i++){
			for(int j=1; j<=k; j++){
				ma=max(ma,dp[l][i][j]);
			}
		}
	}
	cout << ma;
}