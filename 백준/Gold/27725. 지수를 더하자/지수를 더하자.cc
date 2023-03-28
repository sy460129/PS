#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
vector<int>v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x; cin >> n;
	ll k, y, ans=0;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	cin >> k;
	for(int i=0; i<v.size(); i++){
		int cnt=1;
		x=v[i], y=x;
		if(x>k) break;
		while(1){
			if(y<=k){
				ans+=(k/y);
				y*=x;
			}
			else break;
		}
	}
	cout << ans;
}