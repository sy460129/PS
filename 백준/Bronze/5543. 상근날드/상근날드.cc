#include <iostream>
using namespace std;
int main(){
	int n=2001,m=2001,x;
	for(int i=0; i<3; i++){
		cin >> x;
		n=min(n,x);
	}
	for(int i=0; i<2; i++){
		cin >> x;
		m=min(x,m);
	}
	cout << n+m-50;
}