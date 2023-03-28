#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	b=ceil(b/d);
	c=ceil(c/e);
	cout<<a-max(b,c);
}