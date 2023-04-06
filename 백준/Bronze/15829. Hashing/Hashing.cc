#include <iostream>
#define MAX 1234567891
using namespace std;
typedef unsigned long long ll;
ll po(ll m, ll x){
	if(x==0){
		return 1;
	}
	else if(x==1){
		return m;
	}
	else if(x%2!=0){
		return po(m, x-1)*m;
	}
	ll h=po(m, x/2);
	h%=MAX;
	return (h*h)%MAX;
}
int main() {
	ll n, ans=0;
	string s;
	cin >> n >> s;
	for(int i=0; i<n; i++){
		ans+=(po(31,i))%MAX*(s[i]-'a'+1);
		ans%=MAX;
	}
	cout << ans;
}