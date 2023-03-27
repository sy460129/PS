#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cout <<setw(i);
		for(int j=i; j<=n; j++){
			cout << "*";
		}
		cout << "\n";
	}
}