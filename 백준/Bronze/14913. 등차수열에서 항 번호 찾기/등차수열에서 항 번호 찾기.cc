#include <iostream>
using namespace std;
int main(){
	int a, b, k;
	cin >> a >> b >> k;
	if(k==a){
		cout << 1;
		return 0;
	}
	k-=a;
	if(abs(k-a)<abs(k-(a+b))) {
		cout << "X";
		return 0;
	}
	k%b==0 ? cout << k/b+1 : cout << "X";
}