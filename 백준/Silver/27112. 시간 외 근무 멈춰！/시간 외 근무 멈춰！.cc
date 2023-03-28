#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>>v, vec;
int main(){
    int n, x, y, t, p=0, cnt=0, ans=0; cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    for(int j=0; j<v.size(); j++){
		x=v[j].first, y=v[j].second;
		cnt=0;
		for(int i=0; i<x; i++){
			p++;
			if(p%7==6) p+=2;
			if(p>x){
				p--;
				break;
			}
			cnt++;
			if(cnt==y) break;
		}
		if(cnt!=y) vec.push_back({x,y-cnt});
    }
	p=0, cnt=0;
    for(int j=0; j<vec.size(); j++){
		x=vec[j].first, y=vec[j].second;
		cnt=0;
		for(int i=0; i<x; i++){
			p++;
			if(p>x) break;
			cnt++, ans++;
			if(cnt==y) break;
		}
		if(cnt!=y){
			cout << -1;
			return 0;
		}
    }
    cout << ans;
}