#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=n; i>0; i--){
		cout <<setw(i);
		for(int j=n; j>=i; j--){
			cout << "*";
		}
		cout << "\n";
	}
}