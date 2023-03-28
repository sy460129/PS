#include <iostream>
#include <queue>
using namespace std;
typedef unsigned long long ull;
priority_queue<ull>q;
int main() {
	ull ans=0, n, x, y;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		q.push(x);
		ans+=y;
	}
	for(int i=n; i>0; i--){
		ans+=q.top()*i;
		q.pop();
	}
	cout << ans;
}