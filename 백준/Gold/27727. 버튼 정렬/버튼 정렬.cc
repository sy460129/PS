#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
vector<int>v;
bool check;
int main(){
	int n, m=-1; cin >> n;
	ll x, t, cnt=0;
	v.resize(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
		if(i!=0){
			if(v[i-1]>v[i]) m=max(m, v[i-1]);
		}
	}
	cin >> x;
	for(int i=0; i<n; i++){
		if(v[i]<m) {
			check=true;
			cnt+=m-v[i], v[i]=m;
		}
	}
	x-=cnt;
	check ? cnt=1 : cnt=0;
	if(x<0) cout << 0;
	else{
		for(int i=1; i<n; i++){
			t=v[i]-v[i-1];
			if(x>=i){
				if(x>=t*i) x-=t*i, cnt+=t;
				else cnt+=(x/i), x-=((x/i)*i);
			}
			else break;
		}
		if(x>0) cnt+=(x/n);
		cout << cnt;
	}
}