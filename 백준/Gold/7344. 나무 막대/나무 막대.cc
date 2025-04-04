#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int>st[5001];
int main(){
	int n, t, l, ans; cin >> t;
	while(t--){
		ans=0;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> st[i].first >> st[i].second;
		}
		sort(st, st+n);
		for(int i=0; i<n; i++){
			if(st[i].first>10000) continue;
			l=st[i].second;
			ans++;
			for(int j=i+1; j<n; j++){
				if(st[j].first>10000) continue;
				if(st[j].second>=l){
					l=st[j].second;
					st[j].first=10001;
				}
			}
		}
		cout << ans << "\n";
	}
}