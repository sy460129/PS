#include <iostream>
using namespace std;
int a[201];
int main() {
	int n, x;
	cin >> n;
	while(n--){
		cin >> x;
		x+=100;
		a[x]++;
	}
	cin >> x;
	cout << a[x+100];
}