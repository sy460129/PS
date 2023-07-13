#include <iostream>
#include <queue>
using namespace std;
priority_queue<int>q;
int main(){
	int n, h, t, x; cin >> n >> h >> t;
	while(n--){
		cin >> x;
		q.push(x);
	}
	for(int i=0; i<t; i++){
		x=q.top(); q.pop();
		if(x>=h) q.push(max(1,x/2));
		else{
			cout << "YES\n";
			cout << i;
			return 0;
		}
	}
	q.top()<h ? cout << "YES\n" << t : cout << "NO\n" << q.top();
}