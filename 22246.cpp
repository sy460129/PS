#include <iostream>
#include <queue>
using namespace std;
typedef pair<string,string>p;
priority_queue<p,vector<p>,greater<p>>q;
priority_queue<string,vector<string>,greater<string>>ans;
int main(){
	int n, cnt=1;
	string s,c;
	cin >> n;
	if(n==0){
		cout << 0;
		return 0;
	}
	while(n--){
		cin >> s >> c;
		q.push({s,c});
	}
	ans.push(q.top().second);
	q.pop();
	while(!q.empty()){
		while(!ans.empty() && ans.top()<q.top().first){
			ans.pop();
		}
		ans.push(q.top().second);
		q.pop();
		cnt=max(cnt,(int)ans.size());
	}
	cout << cnt;
}