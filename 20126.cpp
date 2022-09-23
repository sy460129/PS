#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int>p;
priority_queue<p, vector<p>, greater<p>>q;
int main(){
	int n, m, s, x, y;
	cin >> n >> m >> s;
	q.push({0,0});
	while(n--){
		cin >> x >> y;
		q.push({x, x+y});
	}
	while(!q.empty()){
		x=q.top().first, y=q.top().second;
		q.pop();
		if(y+m<=q.top().first){
			cout << y;
			return 0;
		}
	}
	if(m+y<=s){
		cout << y;
		return 0;
	}
	cout << -1;
}