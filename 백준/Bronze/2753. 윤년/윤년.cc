#include <iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	if(x%4==0){
		if(x%100!=0) cout << 1;
		else if(x%100==0 && x%400==0) cout << 1;
		else cout << 0;
		return 0;
	}
	cout << 0;
}