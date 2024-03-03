#include <iostream>
#include <vector>
using namespace std;
vector<int>v, v2;
int dp[3001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q, x, m; cin >> n >> q;
	for(int i=0; i<n; i++) cin >> dp[i];
	while(q--){
		m=0;
		cin >> x;
		for(int i=0; i<x; i++){
			if(v.empty() || dp[i]>v.back()){
				v.push_back(dp[i]);
				if(i==x-1) m=v.size()-1;
			}
			else{
				if(dp[x-1]<dp[i]) continue;
				auto it=lower_bound(v.begin(), v.end(), dp[i])-v.begin();
				v[it]=dp[i];
				if(i==x-1) m=it;
			}
		}
		v2.push_back(dp[x-1]);
		for(int i=x; i<n; i++){
			if(dp[i]>v2.back()) v2.push_back(dp[i]);
			else{
				if(dp[x-1]>dp[i]) continue;
				auto it=lower_bound(v2.begin(), v2.end(), dp[i])-v2.begin();
				v2[it]=dp[i];
			}
		}
		cout << m+v2.size() << "\n";
		v.clear(); v2.clear();
	}
}