#include <iostream>
#include <cassert>
using namespace std;
bool c;
int main(){
	unsigned long long x, n;
	while(cin >> n){
		assert(n>1 && n<4294967295);
		x=1;
		c=false;
		while(1){
			if(x>=n){
				c ? cout << "Baekjoon wins.\n" : cout << "Donghyuk wins.\n";
				break;
			}
			if(!c) x*=9, c=!c;
			else x*=2, c=!c;
		}
	}
}