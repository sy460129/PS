#include <iostream>
using namespace std;
int main() {
	int x, a, b;
	cin >> x >> a;
	while(x--){
		cin >> b;
		if(b<a){
			cout << b << " ";
		}
	}
}