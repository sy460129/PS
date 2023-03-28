#include <iostream>
#include <stack>
using namespace std;
stack<int>st[7];
int main(){
	int n, m, x, cnt=0, y; cin >> n >> m;
	while(n--){
		cin >> x >> y;
		if(st[x].empty()) st[x].push(y), cnt++;
		else if(st[x].top()<y) st[x].push(y), cnt++;
		else if(st[x].top()>y){
			while(!st[x].empty() && st[x].top()>y){
				st[x].pop();
				cnt++;
			}
			if(!st[x].empty() && st[x].top()!=y) st[x].push(y),	cnt++;
			else if(st[x].empty()) st[x].push(y), cnt++;
		}
	}
	cout << cnt;
}