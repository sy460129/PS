#include <iostream>
using namespace std;
int dp[101][101];
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> dp[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(dp[j][i]!=0 && dp[i][k]!=0){
					dp[j][k]=1;
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			dp[i][j]==1 ? cout << 1 << " " : cout << 0 << " ";
		}
		cout << "\n";
	}
}