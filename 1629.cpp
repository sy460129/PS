#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull a, b, c;
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
	h%=c;
	return (h*h)%c;
}
int main(){
	cin >> a >> b >> c;
	cout << multi(a, b)%c;
}