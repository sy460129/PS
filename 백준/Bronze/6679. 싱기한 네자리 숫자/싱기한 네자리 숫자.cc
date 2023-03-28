#include <iostream>
using namespace std;
int main(){
	for(int i=2990; i<10000; i++){
		int t = i, ten = 0, two = 0, six = 0;
		while(t != 0){
			ten += t % 10;
			t /= 10;
		}
		t = i;
		while(t != 0){
			two += t % 12;
			t /= 12;
		}
		t = i;
		while(t != 0){
			six += t % 16;
			t /= 16;
		}
		if(ten == two && two == six){
			cout << i << "\n";
		}
	}
}