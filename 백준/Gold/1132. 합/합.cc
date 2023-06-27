#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
using ll=long long;
using p=pair<ll,ll>;
long long al[11], ans;
bool f[11];
vector<p>v;
priority_queue<p>q;
int main(){
	int n; cin >> n;
	string s;
	while(n--){
		cin >> s;
		for(int i=0; i<s.length(); i++){
			al[s[i]-'A']+=pow(10, s.length()-i-1);
			if(i==0) f[s[i]-'A']=true;
		}
	}
	for(int i=0; i<11; i++){
		if(al[i]) q.push({al[i], i});
	}
	while(!q.empty()){
		v.push_back(q.top());
		q.pop();
	}
	int cnt=9;
	if(v.size()!=10){
		for(int i=0; i<v.size(); i++){
			ans+=v[i].first*cnt;
			cnt--;
		}
	}
	else{
		for(int i=v.size()-1; i>=0; i--){
			if(!f[v[i].second]){
				v[i].first=0;
				break;
			}
		}
		for(int i=0; i<v.size(); i++){
			if(v[i].first==0) continue;
			ans+=v[i].first*cnt;
			cnt--;
		}
	}
	cout << ans;
}