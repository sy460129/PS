#include <iostream>
#include <cmath>
using namespace std;
int main(){
	long long n, cnt=0, t, x; cin >> n;
	x=n;
	for(int i=1; i<=n; i++){
		if(x<i) break;
		t=n/i;
		if(n%i) t++;
		cnt+=t;
		if(t*t==n) t++;
		if(t<=i) break;
		cnt+=(x-t+1)*i;
		x=t-1;
	}
	cout << cnt;
}