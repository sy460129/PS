#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
using ll=long long;
using p=pair<ll,ll>;
pair<ll,pair<p,p>>m[2501];
ll ccw(pair<ll,pair<p,p>>a, pair<ll,pair<p,p>>b){
	auto c1=a.second;
	auto c2=b.second;
	ll x1=c1.first.first, y1=c1.first.second, x2=c1.second.first, y2=c1.second.second, x3=c2.first.first, y3=c2.first.second;
	ll t=(x1*y2+x2*y3+x3*y1-(x2*y1+x3*y2+x1*y3));
	return t<0 ? -1 : 1;
}
ll ccw2(pair<ll,pair<p,p>>a, pair<ll,pair<p,p>>b){
	auto c1=a.second;
	auto c2=b.second;
	ll x1=c1.first.first, y1=c1.first.second, x2=c1.second.first, y2=c1.second.second, x3=c2.second.first, y3=c2.second.second;
	ll t=(x1*y2+x2*y3+x3*y1-(x2*y1+x3*y2+x1*y3));
	return t<0 ? -1 : 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n, x1, x2, y1, y2, w; cin >> n;
    unsigned long long ans=0;
	for(int i=0; i<n; i++){
		cin >> x1 >> y1 >> x2 >> y2 >> w;
		m[i]={w,{{x1,y1},{x2,y2}}};
	}
	sort(m, m+n);
	for(int i=0; i<n; i++){
		int tc=0;
		for(int j=i+1; j<n; j++){
			ll a=ccw(m[j],m[i])*ccw2(m[j],m[i]);
			ll b=ccw(m[i],m[j])*ccw2(m[i],m[j]);
			if(a<0 && b<0) tc++;
		}
		ans+=m[i].first*(tc+1);
	}
	cout << ans;
}