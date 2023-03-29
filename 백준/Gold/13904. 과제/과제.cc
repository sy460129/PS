#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>>q;
vector<pair<int,int>>v;
int main(){
	int n, x, y, ans=0;
	cin >> n;
	while(n--){
		cin >>  x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		q.push(v[i].second);
		if(q.size()>v[i].first){
			q.pop();
		}
	}
	while(!q.empty()){
		ans+=q.top();
		q.pop();
	}
	cout << ans;
}