#include <iostream>
#include <vector>
using namespace std;
int n, m, x, answer=2147483647;
vector<pair<int,int>>h, c, a;
bool check[14];
void track(int t){
	if(a.size()==m){
		int ans=0;
		for(int j=0; j<h.size(); j++){
			int res=2147483647;
			for(int i=0; i<a.size(); i++){
				res=min(res, (abs(h[j].first-a[i].first)+abs(h[j].second-a[i].second)));
			}
			ans+=res;
		}
		answer=min(ans, answer);
		return;
	}
	for(int i=t; i<c.size(); i++){
		a.push_back({c[i].first, c[i].second});
		track(i+1);
		a.pop_back();
	}
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> x;
			if(x==1) h.push_back({i,j});
			else if(x==2) c.push_back({i,j});
		}
	}
	track(0);
	cout << answer;
}