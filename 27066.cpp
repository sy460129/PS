#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
	int n,  x, y; cin >> n;
	double t=2, res=0, ans;
	vector<double>v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	sort(v.rbegin(), v.rend());
	ans=v[v.size()/2];
	x=v.back();
	v.pop_back();
	res=x;
	while(!v.empty()){
		y=v.back();
		v.pop_back();
		res+=y;
		v.push_back(res/t);
		ans=max(ans, v[v.size()/2]);
		v.pop_back();
		t++;
	}
	cout << fixed << setprecision(6) << ans;
}