#include <iostream>
using namespace std;
int main(){
	int n, p; cin >> n;
	p=n/5;
	while(1){
		if((n-(p*5))%2==0){
			cout << (n-(p*5))/2+p;
			return 0;
		}
		p--;
		if(p<0) break;
	}
	cout << -1;
}