#include <iostream>
using namespace std;
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int main(){
	int x, y, t; cin >> x >> y;
	t=gcd(x,y);
	cout << t << "\n" << x*y/t;
}