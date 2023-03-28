#include <iostream>
using namespace std;
using ll=long long;
ll ccw(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3){
	ll t=x1*y2+x2*y3+x3*y1-(x2*y1+x3*y2+x1*y3);
	if(t==0) return t;
	return t<0 ? -1 : 1;
}
int main(){
	ll x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	ll a=ccw(x1, x2, x3, y1, y2, y3)*ccw(x1, x2, x4, y1, y2, y4);
	ll b=ccw(x3, x4, x1, y3, y4, y1)*ccw(x3, x4, x2, y3, y4, y2);
	if(a<0 && b<0) cout << 1;
	else cout << 0;
}