#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull MAX=1e9+7;
ull multi(ull x, ull m){
	if(m==0){
		return 1;
	}
	else if(m==1){
		return x;
	}
	else if(m%2!=0){
		return multi(x, m-1)*x;
	}
	ull h=multi(x, m/2);
	h%=MAX;
	return h*h%MAX;
}
int main(){
	ull n;
	cin >> n;
	if(n==0){
		cout << 1;
		return 0;
	}
	cout << multi(2, n-1)%MAX;
}