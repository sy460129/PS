#include <iostream>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
set<ll>s;
int main(){
	ll a, b;
	cin >> a >> b;
	for(ll i=2; i<=sqrt(b); i++){
		ll j=a/(i*i);
		j*=(i*i);
		if(j<a){
			j+=i*i;
		}
		for(ll k=j; k<=b; k+=i*i){
			s.insert(k);
		}

	}
	cout << b-a+1-s.size();
}