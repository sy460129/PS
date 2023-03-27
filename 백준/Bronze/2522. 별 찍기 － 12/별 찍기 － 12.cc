#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cout << setw(n-i);
		for(int j=0; j<=i; j++){
			cout << "*";
		}
		cout << "\n";
	}
	for(int i=1; i<n; i++){
		cout << setw(i+1);
		for(int j=0; j<n-i; j++){
			cout << "*";
		}
		cout << "\n";
	}
}