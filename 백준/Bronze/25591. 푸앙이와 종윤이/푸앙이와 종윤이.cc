#include <iostream>
using namespace std;
int main(){
	int x, y, a, b, c, d, q, r;
    cin >> x >> y;
    a=100-x, b=100-y;
    c=100-(a+b), d=a*b;
    q=d/100, r=d%100;
    cout << a << " " << b << " " << c << " " << d << " " << q << " " << r << "\n";
    cout << x*y/100 << " " << x*y%100;
}