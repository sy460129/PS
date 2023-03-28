#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		cout << s[0] - '0' + s[2] - '0' << "\n";
	}
}