#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<2*n; j++){
			if(j<=i || j>=2*n-i-1){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		cout << "\n";
	}
	for(int i=n-2; i>=0; i--){
		for(int j=0; j<2*n; j++){
			if(j<=i || j>=2*n-i-1){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		cout << "\n";
	}
}