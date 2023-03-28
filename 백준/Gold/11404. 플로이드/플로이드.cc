#include <iostream>
#define INF 10000001
using namespace std;
int dp[101][101];
int main(){
	int n, m, a, b, c;
	cin >> n >> m;
	fill(&dp[0][0], &dp[101][101], INF);
	while(m--){
		cin >> a >> b >> c;
		dp[a][b]=min(dp[a][b], c);
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j){
				dp[i][j]=0;
			}
		}
	}
	for(int i=1; i<=n; i++){ // 중간에 거쳐가는 경로
		for(int j=1; j<=n; j++){ // 시작하는 정점
			for(int k=1; k<=n; k++){ // 도착하는 정점
				if(dp[j][i] + dp[i][k] < dp[j][k]){
					dp[j][k]=dp[j][i] + dp[i][k];
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dp[i][j]==INF){
				dp[i][j]=0;
			}
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
}