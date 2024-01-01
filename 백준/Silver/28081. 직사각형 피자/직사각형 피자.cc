#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
vector<ll>x, y, v, v2;
int main(){
	int w, h, n, m, cnt=1; 
	ll k, ans=0; cin >> w >> h >> k;
	cin >> n;
	x.resize(n+1);
	for(int i=1; i<=n; i++) cin >> x[i];
	for(int i=0; i<n; i++) v.push_back(x[i+1]-x[i]);
	v.push_back(h-x[n]);
	sort(v.begin(), v.end());
	cin >> m;
	y.resize(m+1);
	for(int i=1; i<=m; i++) cin >> y[i];
	for(int i=0; i<m; i++) v2.push_back(y[i+1]-y[i]);
	v2.push_back(w-y[m]);
	int f, e;
	for(int i=0; i<=m; i++){
		f=0, e=v.size()-1;
		while(f<=e){
			int mid=(f+e)/2;
			if(v[mid]*v2[i]>k) e=mid-1;
			else f=mid+1;
		}
		ans+=f;
	}
	cout << ans;
}