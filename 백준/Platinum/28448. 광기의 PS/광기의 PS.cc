#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
ll ans, cnt;
vector<pair<ll, ll>>v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n, l, x, y; cin >> n >> l;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		if(y<=5) ans+=y;
		else v.push_back({x,y});
	}
	sort(v.rbegin(), v.rend());
	for(auto& e: v){
		ans+=e.second;
		cnt+=e.first*e.second;
		if(cnt>l){
			ans+=cnt-l;
			cnt=l;
		}
		cnt-=5*e.first;
	}
	cout << ans;
}