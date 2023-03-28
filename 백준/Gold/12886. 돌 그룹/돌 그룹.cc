#include <iostream>
#include <queue>
using namespace std;
bool arr[1501][1501];
queue<pair<int,int>>q;
int main(){
	int a, b, c, n, m, ma, mi, sum; cin >> a >> b >> c;
	if(a==b && a==c){
		cout << 1;
		return 0;
	}
	sum=a+b+c;
	if(sum%3){
		cout << 0;
		return 0;
	}
	n=min(min(a, b), c), m=max(max(a, b), c);
	a=n, c=m, b=sum-a-c;
	if(a!=b) q.push({a, b}), arr[a][b]=true;
	if(a!=c && !arr[a][c]) q.push({a, c}), arr[a][c]=true;
	if(b!=c && !arr[b][c]) q.push({b, c}), arr[b][c]=true;
	while(!q.empty()){
		a=q.front().first, b=q.front().second; q.pop();
		c=sum-a-b;
		if(a==b && a==c){
			cout << 1;
			return 0;
		}
		n=min(a, b), m=max(a, b);
		m-=n, n*=2;
		mi=min(n, m), ma=max(n, m);
		if(mi>0 && !arr[mi][ma]){
			q.push({mi, ma});
			arr[mi][ma]=true;
		}
		n=min(a, c), m=max(a, c);
		m-=n, n*=2;
		mi=min(n, m), ma=max(n, m);
		if(mi>0 && !arr[mi][ma]){
			q.push({mi, ma});
			arr[mi][ma]=true;
		}
		n=min(b, c), m=max(b, c);
		m-=n, n*=2;
		mi=min(n, m), ma=max(n, m);
		if(mi>0 && !arr[mi][ma]){
			q.push({mi, ma});
			arr[mi][ma]=true;
		}
	}
	cout << 0;
}