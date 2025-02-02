#include <iostream>
#include <queue>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
priority_queue<pll, vector<pll>, greater<pll>>q, tmp;
int main(){
	int n, m, c, d; cin >> n >> m;
	long long hd, hp, a, b, cnt=0;
	for(int i=0; i<n; i++){
		cin >> a >> b >> c >> d;
		if(c) b=0;
		if(d) q.push({(a+1)/2,b/2});
		else q.push({a,b});
	}
	cin >> hd >> hp;
	while(m){
		while(!q.empty() && q.top().first<=hd){
			tmp.push({q.top().second, q.top().first});
			q.pop();
		}
		if(tmp.empty()) break;
		cnt+=max((ll)0, tmp.top().first-hp);
		m--;
		hd++, hp++;
		tmp.pop();
	}
	if(m) cnt=-1;
	cout << cnt;
}