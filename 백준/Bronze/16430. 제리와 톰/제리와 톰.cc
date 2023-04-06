#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	a=b-a;
	for(int i=2; i<=9; i++){
		while(a%i==0 && b%i==0){
			a/=i; b/=i;
		}
	}
	cout << a << " " << b;
}