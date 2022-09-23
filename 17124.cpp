#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int n, m, t, x;
	cin >> t;
	while(t--){
		unsigned long long ans=0;
		vector<int>v1, v2;
		cin >> n >> m;
		for(int i=0; i<n; i++){
			cin >> x;
			v1.push_back(x);
		}
		for(int i=0; i<m; i++){
			cin >> x;
			v2.push_back(x);
		}
		sort(v2.begin(), v2.end());
		for(int i=0; i<n; i++){
			auto a=lower_bound(v2.begin(), v2.end(), v1[i])-v2.begin();
			if(a<=0) ans+=v2[0];
			else if(a>m-1) ans+=v2[m-1];
			else v2[a]-v1[i]<v1[i]-v2[a-1] ? ans+=v2[a] : ans+=v2[a-1];
		}
		cout << ans << "\n";
	}
}