#include <iostream>
#include <vector>
using namespace std;
int n, cnt;
int dp[300001];
int ans[300001];
vector<int>v;
int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		dp[i]=dp[i-1]+i;
		v.empty() ? v.push_back(1) : v.push_back(dp[i]+v.back());
	}
	for(int i=1; i<=n; i++){
		ans[i]=i;
		for(int j=0; j<v.size(); j++){
			if(i>=v[j]){
				ans[i]=min(ans[i], ans[i-v[j]]+1);
			}
			else break;
		}
	}
	cout << ans[n];
}