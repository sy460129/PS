#include <iostream>
using namespace std;
int main(){
	int x, a, b, t;
	cin >> x;
	while(x--){
		cin >> a >> b;
		a%=10;
		b%=4;
		if(b==1){
			t= a%10;
		}
		else if(b==2){
			t= (a*a)%10;
		}
		else if(b==3){
			t= (a*a*a)%10;
		}
		else{
			t= (a*a*a*a)%10;
		}
		if(t==0){
			t=10;
		}
		cout << t << "\n";
	}
}