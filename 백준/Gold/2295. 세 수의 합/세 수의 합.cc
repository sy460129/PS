#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, l, r, m; cin >> n;
	vector<ll>v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for(int i=n-1; i>=1; i--){
		ll res=v[i];
		for(int j=i-1; j>=0; j--){
			ll f=v[j];
			l=0, r=j;
			while(l<=r){
				if(f+v[l]+v[r]==res){
					cout << res;
					return 0;
				}
				else if(f+v[l]+v[r]<res) l++;
				else r--, l=0;
			}
		}
	}
}