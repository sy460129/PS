#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int>v, ans;
	int n, t, x, y; cin >> n;
	for(int i=1; i<=n; i++){
		v.push_back(n);
		x=n;
		t=i;
		v.push_back(t);
		while(1){
			y=x-t;
			x=t, t=y;
			if(t<0) break;
			v.push_back(t);
		}
		if(v.size()>ans.size()) ans=v;
		v.clear();
	}
	cout << ans.size() << "\n";
	for(auto e : ans) cout << e << " ";
}