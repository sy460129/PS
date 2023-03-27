#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n, a, b, x; cin >> a >> b >> n;
	for(int i=0; i<n; i++){
		if(i==0 && a/b>0) a%=b;
		a*=10;
		x=a/b;
		a%=b;
	}
	cout << x;
}