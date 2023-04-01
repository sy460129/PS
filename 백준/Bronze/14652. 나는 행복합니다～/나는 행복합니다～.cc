#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(c<b){
		cout << 0 << " " << c;
	}
	else{
		cout << c/b << " " << c%b;
	}
}