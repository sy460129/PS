#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int dp[5000001];
set<int>s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q, x, y, cur=1; cin >> n >> q;
	for(int i=1; i<=n; i++){
		cin >> dp[i];
		if(dp[i]) s.insert(i);
	}
	while(q--){
		cin >> x;
		if(x==3){
			if(s.empty()) cout << "-1\n";
			else{
				auto it=s.lower_bound(cur);
				if(it!=s.end()) cout << *it-cur << "\n";
				else{
					it=s.lower_bound(1);
					cout << n-cur+(*it) << "\n";
				}
			}
		}
		else{
			cin >> y;
			if(x==1){
				if(dp[y]==1) dp[y]=0, s.erase(y);
				else dp[y]=1, s.insert(y);
			}
			else{
				cur=(cur+y)%n;
				if(!cur) cur=n;
			}
		}
	}
}