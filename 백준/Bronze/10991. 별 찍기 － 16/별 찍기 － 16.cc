#include <iostream>
#define rep_(i, a, b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
	int n; cin >> n;
	rep_(i, 1, n){
		rep_(j, 0, n-i-1){
			cout << " ";
		}
		rep_(j, 0, 2*i-1){
			j%2==0 ? cout << "*" : cout << " ";
		}
		cout << "\n";
	}
}