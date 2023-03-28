#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a,b,c;
	cin>>a>>b;
	c=a*b;
	while(c--){
		if(ceil(c/a)!=b){
			cout << c+1;
			return 0;
		}
	}
}