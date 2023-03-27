#include<iostream>
#include<string>
using namespace std;
int main() {
	int X, count = 0 , A = 0;
	int n = 64;
	cin >> X; //23
	if (n == X) {
		cout << 1;
		return 0;
	}
	while (A != X) {
		n /= 2;
		A += n;
		if (A > X) {
			A -= n;
			count -= 1;
		}
		count += 1;
	}
	cout << count;
}
