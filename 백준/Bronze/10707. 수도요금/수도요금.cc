#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	if(e-c>0){
		cout<<min(a*e, b+(e-c)*d);
	}
	else{
		cout<<min(a*e,b);
	}
}