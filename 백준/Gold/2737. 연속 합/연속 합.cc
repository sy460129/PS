#include <iostream>
using namespace std;
int main(){
	int n, t; cin >> t;
	while(t--){
		cin >> n;
		long long i=2, r=1, cnt=0;
		while(1){
			if(n<=r) break;
			if((n-r)%i==0) cnt++;
			r+=i, i++;
		}
		cout << cnt << "\n";
	}
}