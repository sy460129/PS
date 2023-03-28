#include <iostream>
using namespace std;
int main() {
	int x, a, b;
	cin >> x;
	for(int i=1; i<=x; i++){
		cin >> a >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a+b << "\n";
	}
}