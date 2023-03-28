#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	double a, b, c;
	while(cin>>a>>b){
		c=a/b;
		cout << fixed << setprecision(2) << c<<"\n";
	}
}