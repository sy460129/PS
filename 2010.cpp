#include <iostream>
using namespace std;
int main() {
	int n, x, a=0;
	cin >> n;
	while(n--){
		cin >> x;
		if(a!=0) a--;
		a+=x;
	}
	cout << a;
}