#include <iostream>
using namespace std;
using ll=long long;
ll ask(ll a, ll b){
	cout << "? " << a << " " << b << "\n";
	ll x;
	cin >> x;
	return x;
}
int main(){
	int x;
	for(int i=2; i<=26; i++){
		ll x=ask(1, i);
		ll y=ask(i, 1);
		if(x==-1) cout << "! " << i-1 << "\n";
		if(x!=y) cout << "! " << x+y << "\n";
	}
}