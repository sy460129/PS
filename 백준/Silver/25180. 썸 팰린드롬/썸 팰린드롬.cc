#include <iostream>
using namespace std;
int main(){
	int n, cnt=0;
	cin >> n;
	if(n%9==0){
		cnt=n/9;
	}
	else if((n/9)%2!=0){
		if((n%9)%2!=0){
			cnt=n/9+1;
		}
		else{
			cnt=n/9+2;
		}
	}
	else{
		cnt=n/9+1;
	}
	cout << cnt;
}