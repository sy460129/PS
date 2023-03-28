#include <iostream>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int main() {
	int n; cin >> n;
	rep(i, 0, n-1){
		rep(j, 0, n-i-1){
			cout << " ";
		}
		cout << "*";
		if(i==0) {
			cout << "\n";
			continue;
		}
		rep(j, 0, 2*i-1){
			cout << " ";
		}
		cout << "*\n";
	}
	rep(i, 1, 2*n) cout << "*";
}