#include <iostream>
using namespace std;
using ll=long long;
ll gcd(ll x, ll y){
	return !y ? x : gcd(y, x%y);
}
int main(){
	int n; cin >> n;
	ll x, a1, a2, a3;
	while(n--){
		a3=6;
		cin >> x;
		a1=x*(x-1)*(x-2)/gcd(x*(x-1),(x-2));
		a2=x*(x-1)*(x-3)/gcd(x*(x-1),(x-3));
		a3=(x-1)*(x-2)*(x-3)/gcd((x-1)*(x-2),(x-3));
		cout << max(a1,max(a2,a3)) << "\n";
	}
}