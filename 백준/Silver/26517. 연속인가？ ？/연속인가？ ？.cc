#include<iostream>
using namespace std;
int main() {
	long long x, a, b, c, d; cin >> x >> a >> b >> c >> d;
	if(a*x+b==c*x+d) cout << "Yes " << a*x+b;
	else cout << "No";
}