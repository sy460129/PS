#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double t, x, a, b;
	cin >> x >> a >> b;
	t=sqrt((x*x)/(a*a+b*b));
	cout << (int)(a*t) << " " << (int)(b*t);
}