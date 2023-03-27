#include<iostream>
#include<queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	priority_queue<int, vector<int>, greater<int>>q;
	int n, x;
	cin >> n;
	for(int i=0; i<n*n; i++){
		cin >> x;
		q.push(x);
		if(q.size()>n) q.pop();
	}
	cout << q.top();
}