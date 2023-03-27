#include <iostream>
using namespace std;
int main(){
	int n; cin >> n;
	if(n==1){
		cout << 1 << "\n";
		cout << 1 << " " << 1;
	}
	else{
		cout << 2*n-2 << "\n";
		for(int i=1; i<=n; i++){
			cout << 1 << " " << i << "\n";
		}
		for(int i=2; i<n; i++){
			cout << n << " " << i << "\n";
		}
	}
}