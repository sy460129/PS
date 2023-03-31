#include <iostream>
#include <queue>
using namespace std;
priority_queue<int>q,q2,q3;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b, c, t, ans=0, cnt=0; cin >> n >> m;
	t=m;
	for(int i=0; i<n; i++){
		cin >> a >> b >> c;
		q.push(a+b), q2.push(a+c), q3.push(b+c);
	}
	while(m--){
		cnt+=q.top();
		q.pop();
	}
	ans=max(ans, cnt);
	m=t, cnt=0;
	while(m--){
		cnt+=q2.top();
		q2.pop();
	}
	ans=max(ans, cnt);
	m=t, cnt=0;
	while(m--){
		cnt+=q3.top();
		q3.pop();
	}
	ans=max(ans, cnt);
	cout << ans;
}