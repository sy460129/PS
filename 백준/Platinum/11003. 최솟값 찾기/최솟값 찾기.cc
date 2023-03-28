#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> p;
priority_queue<p,vector<p>,greater<p>>q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, t, x;
	cin >> n >> t;
	for(int i=0; i<n; i++){
		cin >> x;
		q.push({x,i});
		while(q.top().second<=i-t){
			q.pop();
		}
		cout << q.top().first << " ";
	}
}