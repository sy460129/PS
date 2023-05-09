#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using t=tuple<int,int,int>;
priority_queue<t,vector<t>,greater<t>>q;
int arr[2001];
int main(){
	int n, m, c, x, y, z, cnt=0, ans=0; cin >> n >> m >> c;
	while(c--){
		cin >> x >> y >> z;
		q.push({y,x,z});
	}
	while(!q.empty()){
		auto cur=q.top(); q.pop();
		x=get<1>(cur), y=get<0>(cur), z=get<2>(cur);
		cnt=0;
		for(int i=x; i<y; i++) cnt=max(cnt, arr[i]);
		if(cnt<m){
			if(cnt+z<=m){
				for(int i=x; i<y; i++) arr[i]+=z;
				ans+=z;
			}
			else{
				int t=m-cnt;
				for(int i=x; i<y; i++) arr[i]+=t;
				ans+=t;
			}
		}
	}
	cout << ans;
}