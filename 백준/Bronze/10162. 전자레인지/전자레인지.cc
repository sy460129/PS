#include <iostream>
using namespace std;
int main(){
	int n,a=0,b=0,c=0;
	cin >> n;
	while(n>=300){
		n-=300;
		a++;
	}
	while(n>=60){
		n-=60;
		b++;
	}
	while(n>=10){
		n-=10;
		c++;
	}
	if(n==0){
		cout << a << " " << b << " " << c;
	}
	else{
		cout << -1;
	}
}