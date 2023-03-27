#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=n; i>=1; i--){
		cout << setw(i);
		for(int j=1; j<=(n-i)*2+1; j++){
			cout << "*";
		}
		cout << "\n";
	}
	for(int i=2; i<=n; i++){
		cout << setw(i);
		for(int j=(n-i)*2+1; j>=1; j--){
			cout << "*";
		}
		cout << "\n";
	}
}