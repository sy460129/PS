#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	double a,b,c;
	cin>>a>>b>>c;
	cout<<int(max(a*b/c,a/b*c));
}