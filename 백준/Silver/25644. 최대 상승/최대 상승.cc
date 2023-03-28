#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, x, mi=2147483647, ma=0, ans=0; cin >> n;
	vector<int>v;
	for(int i=0; i<n; i++){
		cin >> x;
		ma=max(ma, x);
		mi=min(mi, x);
		if(mi==x) ma=0;
		ans=max(ans, ma-mi);
	}
	cout << ans;
}