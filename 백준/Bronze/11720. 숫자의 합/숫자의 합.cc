#include<iostream>
#include<string>
using namespace std;
int main() {
	int n, x = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		x += s[i] - '0';
	}
	cout << x;
}