#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int n, t;
	cin >> n;
	for(int i=0; i<n; i++){
		cout << setw(i+1);
		for(int j=0; j<2*(n-i)-1; j++){
			cout << "*";
		}
		cout << "\n";
	}
	for(int i=2; i<=n; i++){
		cout << setw(n-i+1);
		for(int j=0; j<2*i-1; j++){
			cout << "*";
		}
		cout << "\n";
	}
}