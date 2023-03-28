#include <iostream>
using namespace std;
int main(){
	int t, n, x;
	cin >> t;
	while(t--){
		int a=0;
		cin >> n;
		while(n--){
			cin >> x;
			a+=x;
		}
		cout << a << "\n";
	}
}