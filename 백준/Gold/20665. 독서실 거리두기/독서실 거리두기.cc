#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
using p=pair<string, string>;
vector<string>v[101];
vector<int>v2;
priority_queue<p, vector<p>, greater<p>>q;
int main(){
	string s, c, start="0900";
	int n, m, k, ans=0, p, a, b, d, e; cin >> n >> m >> k;
	while(m--){
		cin >> s >> c;
		q.push({s,c});
	}
	while(!q.empty()){
		string x=q.top().first, y=q.top().second;
		q.pop();
		for(int i=1; i<=n; i++){
			if(!v[i].empty()){
				if(v[i].back()<=x) v[i].pop_back();
				else v2.push_back(i);
			}
		}
		if(v2.empty()) v[1].push_back(y);
		else{
			int t;
			pair<int,int>cnt={0,0};
			if(v2.size()==1){
				t=v2.back();
				if(t-1>=n-t) v[1].push_back(y);
				else v[n].push_back(y);
			}
			else{
				for(int i=0; i<v2.size()-1; i++){
					t=(v2[i]+v2[i+1])/2; 
					if(cnt.second<t-v2[i]) cnt={t,t-v2[i]};
				}
				if(v2[0]!=1){
					if(v2[0]-1>=cnt.second) cnt={1,v2[0]-1};
				}
				if(v2.back()!=n){
					if(n-v2.back()>cnt.second) cnt={n,n-v2.back()};
				}
				v[cnt.first].push_back(y);
			}
		}
		if(!v[k].empty()){
			if(x>start){
				p=stoi(x);
				a=p/100, b=p%100;
				p=stoi(start);
				d=p/100, e=p%100;
				if(b<e) a--, b+=60;
				ans+=(a-d)*60+b-e;
			}
			start=v[k].back();
		}
		v2.clear();
	}
	a=21, b=0;
	p=stoi(start);
	d=p/100, e=p%100;
	if(b<e) a--, b+=60;
	ans+=(a-d)*60+b-e;
	cout << ans;
}