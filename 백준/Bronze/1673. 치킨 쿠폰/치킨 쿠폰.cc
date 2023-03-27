#include <iostream>
using namespace std;
int main() {
	int n, k, x;
	while(cin >> n >> k){
		int a = n;
		while(n / k != 0){
			a += n / k;
			x = n % k;
			n /= k;
			n += x;
		}
		cout << a << "\n";
	}
}