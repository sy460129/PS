#include<iostream>
int F(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	else {
		return F(n-1) + F(n - 2);
	}
}
using namespace std;
int main() {
	int n;
	cin >> n;
	cout << F(n);
}