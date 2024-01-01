#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
int x[100001], y[100001];
vector<pair<ll, int>>v;
int main(){
	int w, h, n, m, cnt=1; 
	ll k, t, ans=0; cin >> w >> h >> k;
	v.push_back({0,0});
	cin >> n;
	for(int i=1; i<=n; i++) cin >> x[i];
	for(int i=0; i<n; i++) x[i]=x[i+1]-x[i];
	x[n]=h-x[n];
	sort(x, x+n+1);
	for(int i=1; i<=n+1; i++){
		if(x[i]!=x[i-1]) v.push_back({x[i-1],cnt});
		cnt++;
	}
	cin >> m;
	for(int i=1; i<=m; i++) cin >> y[i];
	for(int i=0; i<m; i++) y[i]=y[i+1]-y[i];
	y[m]=w-y[m];
	int f, e;
	for(int i=0; i<=m; i++){
		f=0, e=v.size()-1, t=k/y[i];
		while(f<=e){
			int mid=(f+e)/2;
			if(v[mid].first>t) e=mid-1;
			else f=mid+1;
		}
		ans+=v[(f+e)/2].second;
	}
	cout << ans;
}