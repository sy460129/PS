#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull MAX=1000000007;
ull mul(ull x, ull m){
	if(m==0){
		return 1;
	}
	else if(m==1){
		return x;
	}
	else if(m%2!=0){
		return mul(x, m-1)*x;
	}
	ull h=mul(x, m/2);
	h%=MAX;
	return h*h%MAX;
}
int main(){
	ull n, x;
	cin >> n >> x;
	n%=MAX;
	cout << mul(n, x)%MAX;
}