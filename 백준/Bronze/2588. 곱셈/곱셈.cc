#include <iostream>
using namespace std;
int main() {
	int x, y, s;
	cin >> x >> y;
	s=x*y;
	while(y!=0){
		cout << x*(y%10) << "\n";
		y/=10;
	}
	cout << s;
}