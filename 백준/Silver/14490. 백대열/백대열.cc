#include<iostream>
using namespace std;
int min(int a, int b) {
	int t;
	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main() {
	int a, b;
	char s;
	cin >> a >> s >> b;
	cout << a / min(a, b) << s << b / min(a, b);
}