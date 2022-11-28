#include <iostream>
#include <queue>
using namespace std;
priority_queue<int>q;
priority_queue<int,vector<int>,greater<int>>que;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m,x,t,a;
	cin >> n >> m;
	while(n--){
		cin >> x;
		q.push(x);
	}
	while(m--) que.push(0);
	while(!q.empty()){
		t=q.top()+que.top();
		que.pop();
		q.pop();
		que.push(t);
	}
	while(!que.empty()){
		a=que.top();
		que.pop();
	}
	cout << a;
}