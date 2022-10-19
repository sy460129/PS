#include <iostream>
using namespace std;
bool dp[200002];
int main(){
	int t, n; cin >> t;
	while(t--){
		cin >> n;
		int* arr=new int[n+1];
		dp[0]=true;
		for(int i=1; i<=n; i++) cin >> arr[i];
		for(int i=1; i<=n; i++){
			if(i+arr[i]<=n && dp[i-1]) dp[i+arr[i]]=true;
			if(i-arr[i]>=1 && dp[i-arr[i]-1]) dp[i]=true;
		}
		dp[n] ? cout << "YES\n" : cout << "NO\n";
		fill(dp, dp+n+1, false); 
	}
}