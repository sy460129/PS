#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>>v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x, y, s, e, res=0;
	cin >> n;
	while(n--){
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	s=v[0].first,e=v[0].second;
	for(int i=1; i<v.size(); i++){
		if(v[i].first>e){
			res+=e-s;
			s=v[i].first;
			e=v[i].second;
		}
		else{
			e=max(e,v[i].second);
		}
	}
	res+=e-s;
	cout << res;
}