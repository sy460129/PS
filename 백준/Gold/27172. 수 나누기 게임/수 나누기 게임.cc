#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int arr[1000001];
bool c[1000001];
int dp[100001];
vector<int>v[100001];
int main(){
	int n, x, ans; cin >> n;
	for(int i=0; i<n; i++) cin >> dp[i], c[dp[i]]=true;
	for(int i=0; i<n; i++){
		for(int j=1; j<=sqrt(dp[i]); j++){
			if(dp[i]%j==0 && c[j]) {
				arr[j]++, v[i].push_back(j);
				if(dp[i]/j!=j && c[dp[i]/j]) arr[dp[i]/j]++, v[i].push_back(dp[i]/j);
			}
			else if(dp[i]%j==0 && c[dp[i]/j]) arr[dp[i]/j]++, v[i].push_back(dp[i]/j);
		}
	}
	for(int i=0; i<n; i++){
		ans=arr[dp[i]];
		for(int j=0; j<v[i].size(); j++){
			x=v[i][j];
			if(dp[i]%x==0 && c[x]) ans--;
		}
		cout << ans << " ";
	}
}