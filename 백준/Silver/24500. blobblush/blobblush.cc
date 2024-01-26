#include <iostream>
#include <cmath>
using namespace std;
int main(){
	long long n, i=1, a; cin >> n;
	if(n==1){
		cout << "1\n1";
		return 0;
	}
	while(i<n){
		i*=2;
		if(i==n){
			cout << "2\n" << i-1 << "\n" << i;
			return 0;
		}
	}
	i--;
	a=i^n;
	if(i!=n) cout << "2\n" << a << "\n" << n;
	else cout << "1\n" << n;
}