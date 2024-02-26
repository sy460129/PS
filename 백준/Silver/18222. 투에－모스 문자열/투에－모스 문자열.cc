#include <iostream>
using namespace std;
int main(){
	long long t=1, k, cnt=0; cin >> k;
	while((t<<1)<k) t<<=1;
	while(k>2){
		k-=t, cnt++;
		while(k<=t) t>>=1;
	}
	k==1 ? cout << cnt%2 : cout << (cnt+1)%2;
}