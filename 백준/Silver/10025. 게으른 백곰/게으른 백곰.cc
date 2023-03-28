#include <iostream>
#define MAX 1000000
using namespace std;
int ice[MAX+1];
int main(){
	int n, k, g, x, ans, res=0; cin >> n >> k;
	while(n--){
		cin >> g >> x;
		ice[x]=g;
	}
	for(int i=0; i<=min(2*k,MAX); i++) res+=ice[i];
	ans=res;
	for(int i=2*k+1; i<=MAX; i++){
		res+=ice[i];
		res-=ice[i-2*k-1];
		ans=max(ans,res);
	}
	cout << ans;
}