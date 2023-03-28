#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
	int n; cin >> n;
	double t=2, res=0, ans;
	vector<double>v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	sort(v.rbegin(), v.rend());
	ans=v[v.size()/2];
	res=v.back();
	v.pop_back();
	while(!v.empty()){
		res+=v.back();
		v.pop_back();
		v.push_back(res/t);
		ans=max(ans, v[v.size()/2]);
		v.pop_back();
		t++;
	}
	cout << fixed << setprecision(6) << ans;
}