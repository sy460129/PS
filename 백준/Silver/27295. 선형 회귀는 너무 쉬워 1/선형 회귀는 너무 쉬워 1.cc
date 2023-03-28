#include <iostream>
using namespace std;
using ll=long long;
ll gcd(ll a, ll b){
	return b ? gcd(b, a%b) : a;
}
int main(){
	ll n, b, x, y, p=0; cin >> n >> b;
	b*=n;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		b-=y, p+=x;
	}
	if(p==0) cout << "EZPZ";
	else {
		if((p<0 && b<0) || (p>0 && b>0)) cout << "-";
		if(b%p==0) cout << abs(b)/abs(p);
		else{
			x=gcd(abs(p), abs(b));
			cout << abs(b)/x << "/" << abs(p)/x;
		}
	}
}