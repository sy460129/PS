#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll a, b=0;
	cin >> a;
	for(ll i=1; i<=a; i++){
		b+=i;
		if(b==a){
			b=i;
			break;
		}
		else if(b>a){
			b=i-1;
			break;
		}
	}
	cout << b;
}