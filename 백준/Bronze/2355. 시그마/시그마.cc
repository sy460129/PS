#include <iostream>
using namespace std;
int main() {
	long long x, y;
	cin >> x >> y;
	x<=y ? cout << (x+y)*(y-x+1)/2 : cout << (x-y+1)*(x+y)/2;
}