#include <iostream>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	if(y>=45){
		cout << x << " " << y-45;
	}
	else{
		if(x!=0){
			cout << x-1 << " " << y+15;
		}
		else{
			cout << 23 << " " << y+15;
		}
	}
}