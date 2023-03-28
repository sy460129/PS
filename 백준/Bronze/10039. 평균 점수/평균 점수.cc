#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int x, s=0;
	for(int i=0; i<5; i++){
		cin >> x;
		x=max(x,40);
		s+=x;
	}
	cout << s/5;
}