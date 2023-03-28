#include <iostream>
using namespace std;
int main(){
	int a=0,b=0,x;
	for(int i=0; i<4; i++){
		cin >> x;
		a+=x;
	}
	for(int i=0; i<4; i++){
		cin >> x;
		b+=x;
	}
	cout << max(a,b);
}