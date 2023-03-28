#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
ll n, m, res;
bool check[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	vector<ll>v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
		check[v[i]]=true;
	}
	for(int i=0; i<n-2; i++){
		ll x=v[i];
		for(int j=i+1; j<n-1; j++){
			ll y=v[j], ans, d;
			d=y-x;
			ans=x+y;
			bool c=false;
			if(y+d>1000000) break;
			if(check[y+d]){
				c=true;
				ans+=(y+d);
				y+=d;
			}
			while(1){
				if(y+d>1000000 || !c) break;
				if(check[y+d]){
					ans+=(y+d);
					y+=d;
				}
				else break;
			}
			if(c) res=max(res,ans);
		}
	}
	cout << res;
}