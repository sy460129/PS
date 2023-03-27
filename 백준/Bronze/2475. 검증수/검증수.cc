#include <iostream>
using namespace std;
int main(){
	int n, x=0;
	for(int i=0; i<5; i++){
		cin >> n;
		x+=(n*n)%10;
	}
	x%=10;
	cout << x;
}