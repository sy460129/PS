#include <iostream>
using namespace std;
int x[1001];
int y[1001];
int main() {
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	x[a]++,x[c]++,x[e]++;
	y[b]++,y[d]++,y[f]++;
	if(x[a]==1){
		cout << a << " ";
	}
	else if(x[c]==1){
		cout << c << " ";
	}
	else{
		cout << e << " ";
	}
	if(y[b]==1){
		cout << b;
	}
	else if(y[d]==1){
		cout << d;
	}
	else{
		cout << f;
	}
}