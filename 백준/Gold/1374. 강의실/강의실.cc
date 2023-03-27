#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int>p;
priority_queue<p,vector<p>,greater<p>>q;
priority_queue<int,vector<int>,greater<int>>ans;
int main(){
	int n, a, b, c;
	cin >> n;
	while(n--){
		cin >> a >> b >> c;
		q.push({b,c});
	}
	ans.push(q.top().second);
	q.pop();
	while(!q.empty()){
		if(ans.top()<=q.top().first){
			ans.pop();
		}
		ans.push(q.top().second);
		q.pop();
	}
	cout << (int)ans.size();
}