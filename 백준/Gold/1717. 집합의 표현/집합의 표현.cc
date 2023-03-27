#include <iostream>
using namespace std;
int p[1000001];
int find(int x){
	if(x==p[x]) return x;
	else return p[x]=find(p[x]);
}
void uni(int x, int y){
	x=find(p[x]);
	y=find(p[y]);
	if(x!=y){
		x>y ? p[x]=y : p[y]=x;
	}
}
void f(int x, int y){
	if(find(x)==find(y)) cout << "YES\n";
	else cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	for(int i=1; i<=n; i++) p[i]=i;
	while(m--){
		cin >> a >> b >> c;
		if(a==0) uni(b, c);
		else f(b, c);
	}
}